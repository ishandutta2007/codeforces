//Go to http://threebody.com/ to learn more about THREEBODY.
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define SZ(s) ((int)(s).size())
#define INT long long
#define Mod 1000000007
#define Inf 0x3f3f3f3f
#define SHENBEN "shurongwang"
using namespace std;
//Coded by charlieyan, all rights reserved.
/*                                               
  mmmm                       mmmm     mmm   mmmm 
 m"  "m  m mm  mmmmm         #   "m     #  m"  "m
 #    #  #"  "    m"         #    #     #  #    #
 #    #  #      m"           #    #     #  #    #
  #mm#   #     #mmmm         #mmm"  "mmm"   #mm#"
                                               # 
*/

int a[100007];
int dt[800007],wp[800007];

void change(int now,int nl,int nr,int to,int x){
	if(wp[now]){
		int m=(nl+nr)>>1;
		wp[now<<1]=wp[now];
		wp[now<<1|1]=wp[now]+m-nl+1;
		dt[now<<1]=a[wp[now]];
		dt[now<<1|1]=a[wp[now]+m-nl+1];
		wp[now]=0;
	}
	if(nl==to&&nr==to){
		dt[now]=x;
		return;
	}
	int m=(nl+nr)>>1;
	if(m>=to){
		change(now<<1,nl,m,to,x);
	}else{
		change(now<<1|1,m+1,nr,to,x);
	}
}

void change(int now,int nl,int nr,int l,int r,int frm){
	if(wp[now]){
		int m=(nl+nr)>>1;
		wp[now<<1]=wp[now];
		wp[now<<1|1]=wp[now]+m-nl+1;
		dt[now<<1]=a[wp[now]];
		dt[now<<1|1]=a[wp[now]+m-nl+1];
		wp[now]=0;
	}
	if(nl>=l&&nr<=r){
		dt[now]=a[frm+nl-l];
		wp[now]=frm+nl-l;
		return;
	}
	if(nl>r||nr<l){
		return;
	}
	int m=(nl+nr)>>1;
	change(now<<1,nl,m,l,r,frm);
	change(now<<1|1,m+1,nr,l,r,frm);
}

int num(int now,int nl,int nr,int to){
	if(wp[now]){
		int m=(nl+nr)>>1;
		wp[now<<1]=wp[now];
		wp[now<<1|1]=wp[now]+m-nl+1;
		dt[now<<1]=a[wp[now]];
		dt[now<<1|1]=a[wp[now]+m-nl+1];
		wp[now]=0;
	}
	if(nl==to&&nr==to){
		return dt[now];
	}
	int m=(nl+nr)>>1;
	if(m>=to){
		return num(now<<1,nl,m,to);
	}else{
		return num(now<<1|1,m+1,nr,to);
	}
}

int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		change(1,1,n,i,x);
	}
	for(int i=1;i<=m;i++){
		int CMD;
		scanf("%d",&CMD);
		if(CMD==1){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			change(1,1,n,y,y+k-1,x);
		}else{
			int x;
			scanf("%d",&x);
			printf("%d\n",num(1,1,n,x));
		}
	}
	return 0;
}