#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debug puts("isok")
using namespace std;

int a[1<<9][1<<9],n;

int main(){
    scanf("%d",&n);
    a[1][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<(1<<i-1);j++)
            for(int k=0;k<(1<<i-1);k++)
                a[j][(1<<i)-1-k]=a[j+(1<<i-1)][(1<<i)-1-k]=a[j][k],a[j+(1<<i-1)][k]=a[j][k]^1;
    }
    
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++)
            if(a[i][j]) printf("*"); else printf("+");
        puts("");
    }
    return 0;
}