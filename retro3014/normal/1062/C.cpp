#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
#define MAX_N 100000
#define DIV 1000000007

typedef long long ll;

int N, Q;
string str;
int arr[MAX_N+1];
ll two[MAX_N+1];
int a, b;
ll ans;
ll o, z;


int main(){
    cin>>N>>Q;
    cin>>str;
    two[0]=1;
    for(int i=1; i<=MAX_N; i++){
        two[i]=two[i-1]*2;
        two[i]=two[i]%DIV;
    }
    for(int i=1; i<=N; i++){
        arr[i]=arr[i-1]+(str[i-1]-'0');
    }
    for(int i=1; i<=Q; i++){
        scanf("%d%d", &a, &b);
        o=arr[b]-arr[a-1];
        z=(b-a+1)-o;
        ans=two[o]-1+((two[z]-1)*(two[o]-1)%DIV);
        printf("%lld\n", ans%DIV);
    }
    return 0;
}