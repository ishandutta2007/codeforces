#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
vector<PII> v[2];
int sum[100005];
int n,vo;

int msum(int x){
    if(x>=v[0].size()) return sum[v[0].size()];
    return sum[x];
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &vo);
    int t,c;
    for(int i=0; i<n; i++){
        scanf("%d %d", &t, &c);
        v[t-1].push_back(make_pair(-c, i+1));
    }

    if(vo==1 && v[0].size()==0) {puts("0"); return 0;}

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    sum[0] = 0;
    for(int i=1; i<=v[0].size(); i++){
        sum[i] = sum[i-1] + v[0][i-1].first;
    }

    int s = 0;
    int mx = 0, mid;
    for(int i=0; i<=v[1].size(); i++){
        if(i>0) s+=v[1][i-1].first;
        if(i*2 > vo) break;
        if(s + msum(vo-i*2) < mx){
            mx = s+msum(vo-i*2);
            mid = i;
        }
    }
    printf("%d\n", -mx);
    for(int i=0; i<mid; i++){
        printf("%d ", v[1][i].second);
    }
    for(int i=0; i<vo-mid*2 && i<v[0].size(); i++){
        printf("%d ", v[0][i].second);
    }
}