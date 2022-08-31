#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<set>
#include<string>
#include<map>
#include<vector>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double DB;
const DB pi=acos(-1.0);
map<string,int>dd;
int main(){
	dd["monday"]=0;
	dd["tuesday"]=1;
	dd["wednesday"]=2;
	dd["thursday"]=3;
	dd["friday"]=4;
	dd["saturday"]=5;
	dd["sunday"]=6;
	char a[21];scanf("%s",a+1);
	int day1=dd[a+1];
	scanf("%s",a+1);
	int day2=dd[a+1];
	if((day1+31)%7==day2)printf("YES");
	else if((day1+30)%7==day2)printf("YES");
	else if((day1+28)%7==day2)printf("YES");
	else printf("NO");
	return 0;
}