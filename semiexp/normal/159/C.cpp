#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

struct seg_tree
{
	int N, *data;

	seg_tree()
	{
		N = 0;
		data = NULL;
	}

	seg_tree(int S)
	{
		for(int i=0;;i++){
			if((1<<i) >= S){
				N = 1<<i;
				break;
			}
		}
		data = new int[2*N];
		for(int i=0;i<S;i++) data[i+N] = 1;
		for(int i=S;i<N;i++) data[i+N] = 0;
		for(int i=N-1;i>0;i--) data[i] = data[i*2] + data[i*2+1];
	}

	void decl(int P)
	{
		P += N;
		while(P){
			data[P]--;
			P >>= 1;
		}
	}

	int find(int S)
	{
		int ret = 1;
		while(ret < N){
			if(data[ret*2] >= S){
				ret *= 2;
			}else{
				S -= data[ret*2];
				ret = ret*2 + 1;
			}
		}
		return ret - N;
	}
};

int K, L, N;
char S[200];
vector<int> pos[26];
seg_tree seg[26];
char filled[200000];

int main()
{
	int x; char st[5];

	scanf("%d%s%d", &K, S, &N);
	L = strlen(S);
	for(int i=0;i<K;i++){
		for(int j=0;j<L;j++){
			pos[S[j]-'a'].push_back(i*L+j);
			filled[i*L+j] = S[j];
		}
	}
	for(int i=0;i<26;i++) seg[i] = seg_tree(pos[i].size());
	for(;N--;){
		scanf("%d%s", &x, st);
		int id = st[0]-'a';
		int ps = seg[id].find(x);
		filled[pos[id][ps]] = 0;
		seg[id].decl(ps);
	}
	for(int i=0;i<K*L;i++){
		if(filled[i]) putchar(filled[i]);
	}
	puts("");

	return 0;
}