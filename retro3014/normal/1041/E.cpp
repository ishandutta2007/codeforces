#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

#define MAX_N 1000
using namespace std;

int N;
int a, b;
vector<int> v;
int cnt[MAX_N+1];
vector<int> ans[MAX_N+1];
vector<int> t;

int main(){
    scanf("%d", &N);
    for(int i=1; i<N; i++){
        scanf("%d %d", &a, &b);
        if((a!=N&&b!=N) || (a==N&&b==N) ){
            printf("NO");
            return 0;
        }
        if(a!=N){
            v.push_back(a);
        }
        else{
            v.push_back(b);
        }
    }
    sort(v.begin(), v.end());
    for(int i=N-2; i>=0; i--){
        if(v[i]<i+1){
            printf("NO");
            return 0;
        }
        cnt[v[i]]++;
    }
    printf("YES\n");
    for(int i=N-1; i>=1; i--){
        if(cnt[i]>0){
            ans[i].push_back(i);
            cnt[i]--;
        }
        else{
            for(int j=N-1; j>i; j--){
                if(cnt[j]>0){
                    ans[j].push_back(i);
                    cnt[j]--;
                    break;
                }
            }
        }
    }
    for(int i=1; i<N; i++){
        int tmp=N;
        while(!ans[i].empty()){
            printf("%d %d\n", tmp, ans[i].back());
            tmp=ans[i].back();
            ans[i].pop_back();
        }
    }
    return 0;
}