#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> Ps;
const int N = (int)1e6 + 500, M = (int)1e5 + 500;

int n;
int bit[N], rt[N];
Ps q[M];
int res[M];
string str;

int get(int i){
    int ans = 0;
    while(i){ans += bit[i]; i -= (i&-i);}
    return ans;
}

int add(int i, int val){
    while(i < N){bit[i] += val; i += (i&-i);}
}


int main() {
    getline(cin, str);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d", &q[i].first.first, &q[i].first.second), q[i].second = i;
    sort(q, q+n);

    fill(rt, rt+N, -1);
    stack<int> S;
    str = " " + str;
    for(int i = 1; i < str.length(); i++){
        if(str[i] == '(') S.push(i);
        else if(!S.empty()){
            rt[S.top()] = i;
            add(i, 1);
            S.pop();
        }
    }
    //for(int i = 1; i < str.length(); i++) cout << rt[i] << " ";
    //cout << get(str.length()-1) << endl;
    int las = 0;
    for(int i = 0; i < n; i++){
        for(int j = las; j < q[i].first.first; j++) if(rt[j] != -1) add(rt[j], -1);
        res[q[i].second] = get(q[i].first.second);

        las = q[i].first.first;
    }
    for(int i = 0; i < n; i++){
        printf("%d\n", 2 * res[i]);
    }


}