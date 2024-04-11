#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;

struct student{
    long long idx, skill, pay;
    bool operator <(const struct student &y) const{
        if(skill != y.skill) return skill < y.skill;
        return pay > y.pay;
    }
};

long long N, M, S;
PII bugs[100005];
student stud[100005];
int solv[100005];

long long min_cost(int days){
    long long pass = 0;
    priority_queue<pair<long long, long long> > cost;
    
    int j = N-1;
    for(int i=M-1; i>=0; i-=days){
        while(j>=0 && stud[j].skill >= bugs[i].first){
            cost.push(make_pair(-stud[j].pay, stud[j].idx));
            j--;
        }
        if(!cost.size()) return -1;
        
        for(int j=i; j>max(-1, i-days); j--)
            solv[bugs[j].second] = cost.top().second + 1;
        pass -= cost.top().first;
        cost.pop();
    }

    return pass;
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M >> S;
    for(int i=0; i<M; i++){
        cin >> bugs[i].first;
        bugs[i].second = i;
    }

    for(int i=0; i<N; i++){
        stud[i].idx = i;
        cin >> stud[i].skill;
    }
    for(int i=0; i<N; i++)
        cin >> stud[i].pay;

    sort(bugs, bugs+M);
    sort(stud, stud+N);

    long long lo = 1, hi = M, an = M+1;
    while(lo <= hi){
        long long mi = (lo + hi)/2;
        long long cost = min_cost(mi);
        if(cost != -1 && cost <= S){
            an = mi;
            hi = mi-1;
        }
        else lo = mi+1;
    }

    if(an == M+1) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        min_cost(an);
        for(int i=0; i<M; i++)
            cout << solv[i] << " ";
        cout << endl;
    }
    
    return 0;
}