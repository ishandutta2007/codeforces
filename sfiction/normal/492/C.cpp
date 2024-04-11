/*
ID: Sfiction
OJ: CF
PROB: 492C
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN=100000+100;

int n,r,avg;
long long require,sum;
int a[MAXN][2];

int Comp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    scanf("%d%d%d",&n,&r,&avg);
    require=n*(long long)avg;
    sum=0;
    for (int i=0;i<n;++i){
        scanf("%d%d",&a[i][1],&a[i][0]);
        sum+=a[i][1];
    }
    qsort(a,n,sizeof(a[0]),Comp);
    long long t,cost=0;
    for (int i=0;sum<require;++i){
        t=min((long long)r-a[i][1],require-sum);
        sum+=t;
        cost+=t*a[i][0];
    }
    cout<<cost<<endl;
    return 0;
}