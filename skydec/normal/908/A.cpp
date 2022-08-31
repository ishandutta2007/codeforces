#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=55;
char a[N];
int n;
bool is[277];
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	is['a']=is['e']=is['i']=is['o']=is['u']=1;
	int ans=0;
	rep(i,1,n){
		if(a[i]<='z'&&a[i]>='a'){
			if(is[a[i]])ans++;
		}
		else{
			if((a[i]-'0')%2==1)ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}