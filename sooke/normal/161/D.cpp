#include <cstdio>
#include <algorithm>
#define Maxn 50005
#define Inf 2147483647
#define Max(x , y) ((x) > (y) ? (x) : (y))
#define Min(x , y) ((x) < (y) ? (x) : (y))

using namespace std;

inline int Read(){
    char c = getchar();
    int n = 0;
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9')
        n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
    return n;
}

struct List{
    int len , fst[Maxn] , nxt[Maxn << 1] , v[Maxn << 1] , s[Maxn << 1];
    inline void Init(int d){
        for(int i = 1 ; i <= d ; i++)
            fst[i] = -1;
        len = 0;
    }
    inline void Insert(int _u , int _v){
        v[len] = _v;
        nxt[len] = fst[_u];
        fst[_u] = len++;
    }
};

List L;
int n , k , cor , _min , cnt , sum , siz[Maxn] , dis[Maxn];
bool vis[Maxn];
long long ans;

void Core(int u , int f , int _s){
	siz[u] = 1;
	int _max = 0;
	for(int i = L.fst[u] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i];
		if(v != f && !vis[v]){
			Core(v , u , _s);
			siz[u] += siz[v];
			_max = Max(_max , siz[v]);
		}
	}
	if(_min > Max(_max , _s - siz[u])){
		_min = Max(_max , _s - siz[u]);
		cor = u;
	}
}

void Dfs(int u , int f , int _dis){
	dis[++cnt] = _dis;
	siz[u] = 1;
	for(int i = L.fst[u] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i];
		if(v != f && !vis[v]){
			Dfs(v , u , _dis + 1);
			siz[u] += siz[v];
		}
	}
}

void Solve(int u , int f , int _s){
	_min = Inf;
	Core(u , f , _s);
	int c = cor;
	vis[c] = true;
	cnt = sum = 0;
	for(int i = L.fst[c] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i];
		if(!vis[v]){
			Dfs(v , c , 1);
			L.s[i] = siz[v];
			sort(dis + sum + 1 , dis + sum + siz[v] + 1);
			for(int l = sum + 1 , r = sum + siz[v] ; l <= r ; l++){
				while(l <= r && dis[l] + dis[r] > k)
					r--;
				if(l <= r && dis[l] + dis[r] == k){
					if(dis[l] == dis[r]){
						ans -= 1LL * (r - l + 1) * (r - l + 2) / 2;
						break;
					}else{
						int ansl = 1 , ansr = 1;
						while(dis[l] == dis[l + 1])
							ansl++ , l++;
						while(dis[r] == dis[r - 1])
							ansr++ , r--;
						ans -= 1LL * ansl * ansr;
					}
				}
			}
			sum += siz[v];
		}
	}
	sort(dis + 1 , dis + sum + 1);
	for(int l = 0 , r = sum ; l <= r ; l++){
		while(l <= r && dis[l] + dis[r] > k)
			r--;
		if(l <= r && dis[l] + dis[r] == k){
			if(dis[l] == dis[r]){
				ans += 1LL * (r - l + 1) * (r - l + 2) / 2;
				break;
			}else{
				int ansl = 1 , ansr = 1;
				while(dis[l] == dis[l + 1])
					ansl++ , l++;
				while(dis[r] == dis[r - 1])
					ansr++ , r--;
				ans += 1LL * ansl * ansr;
			}
		}
	}
	for(int i = L.fst[c] ; i != -1 ; i = L.nxt[i]){
		int v = L.v[i] , s = L.s[i];
		if(!vis[v])
			Solve(v , c , s);
	}
}

int main(){
	n = Read() , k = Read();
    L.Init(n);
    for(int i = 2 ; i <= n ; i++){
        int u = Read() , v = Read();
        L.Insert(u , v);
        L.Insert(v , u);
    }
    Solve(1 , 0 , n);
    printf("%I64d\n" , ans);
    return 0;
}

// By Sooke.
// CF161D Distance in Tree.