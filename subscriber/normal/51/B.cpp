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

vector<int> ans;

string get(){
	string q="";
	while (q.size()==0||q[q.size()-1]!='>'){
		char u=' ';
		while (u<'/')u=getchar(); 
		q+=u;
	}
	return q;
}

void rec(){
	int x=0;
	for (;;){
		string u=get();
		if (u=="</table>"){
			ans.push_back(x);
			return;
		}
		if (u=="<td>")x++;
		if (u=="<table>")rec();
	}	
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	get();
	rec();
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size()-1;i++)cout << ans[i] << " ";
	cout << ans[ans.size()-1] << endl;
	return 0;
}