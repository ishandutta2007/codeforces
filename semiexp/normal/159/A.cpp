#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

int N, D, P;
map<string, int> M;
string name[2000];
char in1[99], in2[99]; int T;
int send[2000][2000];
bool flg[2000][2000];

int v1[1000], v2[1000], t[1000];

int main()
{
	P = 0;
	scanf("%d%d", &N, &D);
	for(int i=0;i<2000;i++)
		for(int j=0;j<2000;j++){
			send[i][j] = -100000;
			flg[i][j] = false;
		}

	for(int i=0;i<N;i++){
		scanf("%s%s%d", in1, in2, &T);
		if(M.count(string(in1))==0){
			name[P] = string(in1);
			M.insert(make_pair(string(in1), P++));
		}
		if(M.count(string(in2))==0){
			name[P] = string(in2);
			M.insert(make_pair(string(in2), P++));
		}

		v1[i] = M[string(in1)]; v2[i] = M[string(in2)]; t[i] = T;
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			if(v1[i]==v2[j]&&v1[j]==v2[i]&&0<t[i]-t[j]&&t[i]-t[j]<=D) flg[v1[i]][v2[i]] = true;
		}
	}
	int pr = 0;
	for(int i=0;i<P;i++)
		for(int j=i+1;j<P;j++) if(flg[i][j]||flg[j][i]) pr++;
	printf("%d\n", pr);
	for(int i=0;i<P;i++)
		for(int j=i+1;j<P;j++){
			if(flg[i][j]||flg[j][i]) printf("%s %s\n", name[i].c_str(), name[j].c_str());
		}

	return 0;
}