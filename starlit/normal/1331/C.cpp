#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n;
	m|=(n>>5&1)<<5;
	m|=(n&1)<<4;
	m|=(n>>2&1)<<3;
	m|=(n>>3&1)<<2;
	m|=(n>>1&1)<<1;
	m|=(n>>4&1);
	cout<<m;
}