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
using namespace std;

int cnt=0;
int n;
long long a[200005];

void find_from(int x){
	if(x==n){
		return;
	}
	cnt++;
	int excnt=0;
	int i=x;
	for(;a[i]==-1&&i<n;i++){
		excnt++;
	}
	if(i==n){
		return;
	}
	int pos1=i,pos2=-1;
	for(i++;i<n;i++){
		if(a[i]!=-1){
			pos2=i;
			break;
		}
	}
	if(i==n){
		return;
	}
	if((a[pos2]-a[pos1])%(pos2-pos1)){
		find_from(pos2);
		return;
	}
	long long xar=(a[pos2]-a[pos1])/(pos2-pos1);
	if(a[pos1]-xar*(pos1-x)<=0){
		find_from(pos2);
		return;
	}
	long long now=a[pos2];
	for(;i<n;i++){
		if(now<=0){
			break;
		}
		if(a[i]!=-1&&a[i]!=now){
			break;
		}
		now+=xar;
	}
	find_from(i);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%I64d",a+i);
	}
	find_from(0);
	printf("%d",cnt);
	return 0;
}