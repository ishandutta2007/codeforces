#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, X;
set<int> S;
vector<int> V;

int main(){
    scanf("%d %d", &N, &X);
    for (int i=1; i<(1<<N); i++) S.insert(i);
    S.erase(X);
    V.push_back(0);
    while (!S.empty()){
        int k = *S.begin();
        V.push_back(k);
        S.erase(k ^ X);
        S.erase(k);
    }
    printf("%d\n", V.size()-1);
    for (int i=1; i<(int)V.size(); i++) printf("%d ", V[i]^V[i-1]);
    return 0;
}