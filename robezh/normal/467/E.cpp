#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 500;

int n;
int num[N];
vector<int> res;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    int cur = 0;
    while(cur < n){
        int t;
        map<int, int> belong, cnt;
        stack <int> S;
        int i;
        for(i = cur; i < n; i++){
            t = belong[num[i]];
            if(t > 0){res.push_back(t); res.push_back(num[i]); break;}
            while(!S.empty() && cnt[num[i]] + (S.top() != num[i]) > 1){
                belong[S.top()] = num[i]; cnt[S.top()]--; S.pop();
            }
            S.push(num[i]); cnt[num[i]]++;
        }
        cur = i + 1;
    }
    printf("%d\n", res.size() * 2);
    for(int i = 0; i < res.size(); i += 2){
        printf("%d %d ", res[i], res[i+1]);
        printf("%d %d ", res[i], res[i+1]);
    }
}