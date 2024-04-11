#include<bits/stdc++.h>



#define NN 211111

using namespace std;



char tmp[2][30];

int goal[5], miss[5], point[5], id[5];

map<string, int> nm;

map<int,int> vst;

map<int, string> name;





int cmp(int u, int v){

	if(point[u]==point[v]){

		if(goal[u]-miss[u]==goal[v]-miss[v]){

			if(goal[u]==goal[v]){

				return name[u]<name[v];

			}

			return goal[u]>goal[v];

		}

		return goal[u]-miss[u]>goal[v]-miss[v];

	}

	return point[u]>point[v];

}



int main(){

	int n,i,j, u, v;

	int np=2;

	nm["BERLAND"]=1;

	name[1]="BERLAND";

	

	for(i=0; i<5; i++){

		scanf("%s %s %d:%d", tmp, tmp+1, &u, &v);

		

		if(!nm[tmp[0]]) nm[tmp[0]]=np++, name[np-1]=tmp[0];

		if(!nm[tmp[1]]) nm[tmp[1]]=np++, name[np-1]=tmp[1];

		

		goal[nm[tmp[0]]]+=u, goal[nm[tmp[1]]]+=v;

		miss[nm[tmp[0]]]+=v, miss[nm[tmp[1]]]+=u;

		vst[nm[tmp[0]]]++, vst[nm[tmp[1]]]++;

		

		if(u>v) point[nm[tmp[0]]]+=3;

		if(u<v) point[nm[tmp[1]]]+=3;

		if(u==v) point[nm[tmp[0]]]++, point[nm[tmp[1]]]++;

		

	}

	

	int team;

	for(i=2; i<=4; i++){

		if(vst[i]==2) team=i;

	}

	

//	for(i=1; i<=4; i++) {

//		cout<<i<<' '<<name[i]<<' '<<point[i]<<' '<<goal[i]<<' '<<miss[i]<<endl;

//	}

	

	

	int ans[2], d=100000;

	for(i=0; i<300; i++){

		for(j=0; j<i; j++){

			for(int k=1; k<=4; k++) id[k]=k;

			

			goal[1]+=i, goal[team]+=j;

			miss[1]+=j, miss[team]+=i;

			point[1]+=3;

			

			sort(id+1,id+5, cmp);

//			cout<<i<<' '<<j<<endl;

//			for(int k=1; k<=4; k++){

//				cout<<id[k]<<' '<<name[id[k]]<<' '<<point[id[k]]<<' '<<goal[id[k]]<<' '<<miss[id[k]]<<endl;

//			}

//			puts("");

			if(id[1]==1 || id[2]==1) {

				if(i-j<d){

					ans[0]=i, ans[1]=j;

//					cout<<"-->"<<i<<' '<<j<<' '<<d<<endl;

					d=i-j;

				}

				

				if(i-j==d) {

//					cout<<"<--"<<i<<' '<<j<<' '<<ans[1]<<endl;

					if(j<ans[1]) {

						ans[0]=i;

						ans[1]=j;

					}

				}

				

			}

			

			goal[1]-=i, goal[team]-=j;

			miss[1]-=j, miss[team]-=i;

			point[1]-=3;

		}

	}

	

	if(d==100000) puts("IMPOSSIBLE");

	else cout<<ans[0]<<':'<<ans[1]<<endl;

	

	

}