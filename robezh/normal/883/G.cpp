#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef pair<int, int> P;

map<P, int> M;

struct edge{
	int to, t;
	edge(int _to, int _t){
		to = _to;
		t = _t;
	}
};

int m,n,s;
vector<edge> G[300050];
int cnnted[300050];
int cnt = 0;
P Pud[300050];
int Pud_size = 0;

//int dfs_max(int k){
//	cnnted[k] = true;
//	cnt++;
//	for(int i = 0; i < G[k].size(); i++){
//		edge e = G[k][i];
//		if(cnnted[e.to]) continue;
//		
//		if(e.t == 1) dfs_max(e.to);
//		else{
//			M[P(k,e.to)] = 1;
//			dfs_max(e.to);
//		}
//	}
//}
//
//int dfs_min(int k){
//	cnnted[k] = true;
//	cnt++;
//	for(int i = 0; i < G[k].size(); i++){
//		edge e = G[k][i];
//		if(cnnted[e.to]) continue;
//		
//		if(e.t == 1) dfs_min(e.to);
//		else M[P(k,e.to)] = -1;
//	}
//}

int dfs(int k, int t){
	cnnted[k] = true;
	cnt++;
	for(int i =0 ; i < G[k].size(); i++){
		edge e = G[k][i];
		if(cnnted[e.to]) continue;
		
		if(e.t == 1) dfs(e.to, t);
		else{
			if(t == 1){
				M[P(k,e.to)] = 1;
			    dfs(e.to, t);
			}
			else{
				M[P(k,e.to)] = 1;
			}
		}
	}
}

//void max_ans() {
//    fill(cnnted+1, cnnted+n+1, false);
//    cnt = 0;
//    
//    dfs_max(s);
//    //cout << "1";
//    cout<<cnt<<endl;
//    
//    for(int i = 0; i < Pud_size; i++){
//    	P p1 = Pud[i];
//    	P p2 = P(Pud[i].second, Pud[i].first);
//    	if(!M.count(p2)){
//    		cout << "+";
//		}
//		else{
//			cout << "-";
//		}
//	}
//	cout << endl;
//}
//
//void min_ans() {
//    M.clear();
//	fill(cnnted+1, cnnted+n+1, false);
//    cnt = 0;
//    
//    dfs_min(s);
//    cout<<cnt<<endl;
//    
//    for(int i = 0; i < Pud_size; i++){
//    	P p1 = Pud[i];
//    	P p2 = P(Pud[i].second, Pud[i].first);
//    	if(!M.count(p2)){
//    		cout << "-";
//		}
//		else{
//			cout << "+";
//		}
//	}
//	cout << endl;
//}

void get_ans(int t){
	M.clear();
	fill(cnnted+1, cnnted+n+1, false);
    cnt = 0;
    
    dfs(s,t);
    cout<<cnt<<endl;
    
    for(int i = 0; i < Pud_size; i++){
    	P p1 = Pud[i];
    	P p2 = P(Pud[i].second, Pud[i].first);
    	if(!M.count(p2)){
    		cout << (t == 1 ? "+" : "-");
		}
		else{
			cout << (t == 1 ? "-" : "+");
		}
	}
	cout << endl;
}

void solve(int ty){
	
}

int main() {

    int from,to,t;
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &t,&from,&to);
        if(t == 1) G[from].push_back(edge(to,1));
        else {
            G[from].push_back(edge(to,2));
            G[to].push_back(edge(from,2));
            Pud[Pud_size++] = P(from, to);
        }
    }
    get_ans(1);
    get_ans(2);
    
    return 0;
}