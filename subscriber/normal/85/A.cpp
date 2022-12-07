#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int n,t;
string s1,s2,s3,s4;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n/2;i++){
		if (!t)s1+="aa";else s1+="bb";
		if (t)s2+="aa";else s2+="bb";
		t^=1;
	}
	if (n%2){
		s1+="c";
		s2+="c";
	}
	s3+="d";
	s4+="d";
	n--;
	for (int i=0;i<n/2;i++){
		if (!t)s3+="ee";else s3+="ff";
		if (t)s4+="ee";else s4+="ff";
		t^=1;
	}
	if (n%2){
		s3+="h";
		s4+="h";
	}
	cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;
	return 0;
}