#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int k;

string f(int x){
	string r="",rr="";
	while (x){
		r+=(char)x%k+'0';
		x/=k;
	}
	for(int i=r.length()-1;i>=0;i--)rr+=r[i];
	return rr;
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> k;
	for (int i=1;i<k;i++){
		for (int j=1;j<k-1;j++)cout << f(i*j) << " ";
		cout << f(i*(k-1))<< endl;
	}
	return 0;
}