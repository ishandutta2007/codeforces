#include<bits/stdc++.h>
using namespace std;
int n,flag;
string st;
int main(){
	cin>>n>>st;
	for(int i=0;i<st.size();++i){
		if(!flag&&(i==st.size()-1||st[i]>st[i+1])){
			flag=1;
		}
		else putchar(st[i]);
	}
	return 0;
}