#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 1000
#define ll long long
struct Node{
	int id;
	ll s;
	friend bool operator <(Node p,Node q){
		return p.s<q.s;
	}
}node;
vector<Node> a[2];
vector<int> ans;
stack<int> st;
int main(){
	fflush(stdout);
	int n;
	scanf("%d",&n);
	int tmp;
	for(int i=3;i<=n;i++){
		cout<<"1 1 2 "<<i<<endl;
		cin>>node.s;
		node.id=i;
		cout<<"2 1 2 "<<i<<endl;
		scanf("%d",&tmp);
		if(tmp<0){
			a[1].push_back(node);
		}
		else{
			a[0].push_back(node);
		}
	}
	sort(a[0].begin(),a[0].end());
	sort(a[1].begin(),a[1].end());
	ans.push_back(1);
	if(!a[1].empty()){
		ans.push_back(a[1][0].id);
		for(int i=1;i<(int)a[1].size();i++){
			cout<<"2 1 "<<a[1][i].id<<' '<<ans.back()<<endl;
			scanf("%d",&tmp);
			if(tmp>0){
				st.push(ans.back());
				ans.pop_back();
			}
			ans.push_back(a[1][i].id);
		}
		while(!st.empty()){
			ans.push_back(st.top());
			st.pop();
		}
	}
	ans.push_back(2);
	if(!a[0].empty()){
		ans.push_back(a[0][0].id);
		for(int i=1;i<(int)a[0].size();i++){
			cout<<"2 2 "<<a[0][i].id<<' '<<ans.back()<<endl;
			scanf("%d",&tmp);
			if(tmp>0){
				st.push(ans.back());
				ans.pop_back();
			}
			ans.push_back(a[0][i].id);
		}
		while(!st.empty()){
			ans.push_back(st.top());
			st.pop();
		}
	}
	cout<<"0 ";
	for(int i=0;i<(int)ans.size();i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}/**/
/*#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 1000
vector<int> ans;
stack<int> st;
struct Node{
	int s;
	int id;
	friend bool operator <(Node p,Node q){
		return p.s<q.s;
	}
}node[Maxn+5];
vector<Node> a[2];
int main(){
	fflush(stdout);
	int n;
	scanf("%d",&n);
	int tmp;
	for(int i=3;i<=n;i++){
		cout<<"1 1 2 "<<i<<endl;
		cin>>node[i].s;
		node[i].id=i;
		cout<<"2 1 2 "<<i<<endl;
		cin>>tmp;
		if(tmp>0){
			a[0].push_back(node[i]);
		}
		else{
			a[1].push_back(node[i]);
		}
	}
	sort(a[0].begin(),a[0].end());
	sort(a[1].begin(),a[1].end());
	if(!a[0].empty()){
		ans.push_back(a[0][0].id);
	}
	for(int i=1;i<(int)a[0].size();i++){
		cout<<"2 1 "<<a[0][i].id<<' '<<ans.back()<<endl;
		cin>>tmp;
		if(tmp<0){
			st.push(ans.back());
			ans.pop_back();
		}
		ans.push_back(a[0][i].id);
	}
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	ans.push_back(2);
	if(!a[1].empty()){
		ans.push_back(a[1][0].id);
	}
	for(int i=1;i<(int)a[1].size();i++){
		cout<<"2 2 "<<a[1][i].id<<' '<<ans.back()<<endl;
		cin>>tmp;
		if(tmp<0){
			st.push(ans.back());
			ans.pop_back();
		}
		ans.push_back(a[1][i].id);
	}
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	cout<<"0 1 ";
	while(!ans.empty()){
		cout<<ans.back()<<' ';
		ans.pop_back();
	}
	cout<<endl;
	return 0;
}*/