#include<bits/stdc++.h>



#define  NN 100050



using namespace std;

typedef pair <int ,int> pii;

pii stu[NN];



int main(){

//	freopen("in.txt","r",stdin);

	int n;

	cin>>n;

	for(int i=0;i<n;i++) scanf("%d",&stu[i].first);

	for(int i=0;i<n;i++) scanf("%d",&stu[i].second);

	sort(stu,stu+n);

	for(int i=0;i<n;i++) 

	printf("%d ",stu[i].second);

	return 0;



}