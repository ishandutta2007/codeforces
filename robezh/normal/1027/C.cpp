#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500, M = (int)1e4 + 500;

int T;
int n, a;
int num[N];
int cnt[M];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        sort(num, num+n);
        vector<int> V;
        for(int i = 0; i < n;){
            int j = i;
            while(num[i] == num[j] && j < n) j++;
            if(j - i >= 2) V.push_back(num[i]);
            if(j - i >= 4) V.push_back(num[i]);
            i = j;
        }
        int mxi = 0;
        double mx = (double)V[0] / V[1];
        for(int i = 1; i < V.size()-1; i++){
            if((double)V[i] / V[i+1] > mx){
                mxi = i;
                mx = (double)V[i] / V[i+1];
            }
        }
        printf("%d %d %d %d\n", V[mxi], V[mxi], V[mxi+1], V[mxi+1]);
    }
}