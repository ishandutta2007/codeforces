//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 2e6 + 9;
typedef long long ll;
int fen[Maxn],arr[Maxn],ans[Maxn];
pair<int,pair<int,int > > do_query[Maxn* 10];
void update(int pos){
//	pos++;
	for(pos;pos < Maxn;pos+=pos&-pos)
		fen[pos]++;
}
int get(int pos){
//	pos++;
	if(!pos) return 0;
	int ret = 0;
	for(pos;pos;pos-=pos&-pos)
		ret += fen[pos];
	return ret;
}
int query(int l,int r){
	return get(r) - get(l - 1);
}
int main(){
	int n;
	scanf("%d",&n);
	For(i,0,n){
		scanf("%d",&arr[i]);
	}
	int pt = 0;
	For(i,0,n){
		do_query[pt++] = make_pair(arr[i],make_pair(Maxn,i));
	}
	For(k,1,n){
		for(int i = 1;(i - 1) * k + 2 <= n;i++){
			do_query[pt++] = make_pair(arr[i-1],make_pair(k,i));
		}
	}
	sort(do_query,do_query+pt);
	For(i,0,pt){
		int num = do_query[i].first,k = do_query[i].second.first,id = do_query[i].second.second;
//		cerr << num << ' ' << k << ' ' << id << endl;
		if(k == Maxn){
			update(id+1);
		}else{
			int l = (k * (id - 1)) + 2;
			int r = min(n,k * id + 1);
			ans[k] += query(l,r);
//			cerr << query(l,r) << " hahah " << l << ' ' << r << endl;
		}
	}
	For(i,1,n){
		printf("%d ",ans[i]);
	}
	return 0;
}