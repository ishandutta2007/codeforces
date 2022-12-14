#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <deque>
#include <string>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define INF 2000000000
#define MAX_N 200000

typedef long long ll;

string str;
int N, K;
vector<int> v;

int chk[MAX_N+1];

int main(){
    scanf("%d%d", &N, &K);
    cin>>str;
    K=(N-K)/2;
    for(int i=0; i<N; i++){
        if(str[i]=='('){
            v.push_back(i);
        }
        else{
            if(K>0){
                K--;
                chk[i]=true;
                chk[v.back()]=true;
                v.pop_back();
            }
            else{
                v.pop_back();
            }
        }
    }
    for(int i=0; i<N; i++){
        if(!chk[i]){
            printf("%c", str[i]);
        }
    }
    return 0;
}