#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
	scanf("%I64d%I64d",&n,&k);
	printf("%I64d",max(min(k-1>>1,n-(k>>1)),0ll));
}