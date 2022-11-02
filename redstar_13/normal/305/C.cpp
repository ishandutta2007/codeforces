#include<bits/stdc++.h>



using namespace std;

typedef long long INT;



set<INT> vst;

map<INT ,int> cnt;

set<INT>::iterator it;



int main(){

//	freopen("in.txt","r",stdin);	

	int n;

	INT a,aa;

	cin>>n;

	for(int i=1;i<=n;i++){

		scanf("%I64d",&a); 

		vst.insert(a);

		cnt[a]++;

	}

	for(it=vst.begin();it!=vst.end();it++){

		aa=*it;

		while(cnt[aa]>=2){

			int k=cnt[aa]/2;

			int kk=cnt[aa]%2;

			if(k>=1) {

				vst.insert(aa+1); cnt[aa+1]+=k; cnt[aa]=kk;

				if(kk==0) vst.erase(aa);

			}

			aa++;

		}

	}

	INT ans=*(--vst.end())-(int)vst.size()+1;



	cout<<ans<<endl;

	return 0;

}