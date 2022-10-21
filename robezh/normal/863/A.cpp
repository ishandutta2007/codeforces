#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	string a;
	getline(cin,a);
	int leftpos = 0; int rightpos = a.length() - 1;
	//while(a[leftpos] == '0') leftpos ++;
	while(a[rightpos] == '0') rightpos --;
	bool res = true;
	while(leftpos < rightpos){
		if(a[leftpos] != a[rightpos]){
			//cout<<leftpos<<" "<<rightpos<<endl;
			res = false;
		}
		leftpos ++; rightpos --;
	}
	if(res) printf("YES");
	else printf("NO");
}