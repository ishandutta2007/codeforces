#include<bits/stdc++.h>
using namespace std;

int n;
char s[100005];
bool check(int x){
	int j=0;
	for(int i=0;i<n;i++){
		while(i<n&&s[i]!='P')i++;
		while(j<n&&s[j]!='*')j++;
		if(i>=n||j>=n)break;
		if(j<i-x)return 0;
		if(j<i){
			int k=max(max(i,j*2+x-i),i+(x-i+j)/2);
			j=k+1;
		}else{
			int k=i+x;
			j=max(j,k+1);
		}
	}
	return j>=n;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	int h=0,t=n*2;
	while(h<t){
		int x=h+t>>1;
		if(check(x))t=x;else h=x+1;
	}
	printf("%d\n",h);
	return 0;
}