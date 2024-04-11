#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000
using namespace std;
int n, m;
vector<vector<int>>adjlist;
set<int>visited;


struct Comparedistance {
	bool operator()(int const& p1, int const& p2) {

		return p1 > p2;
	}
};
priority_queue<int, vector<int>,Comparedistance>pq;

void BFS(int ind) {
	cout << ind + 1 << " ";
	rep(i, 0, adjlist[ind].size()) {
		if (!visited.count(adjlist[ind][i])) {
			visited.insert(adjlist[ind][i]);
			pq.push(adjlist[ind][i]);
		}
	}
	return;
}
int main(){

	cin >> n >> m;
	adjlist.resize(n);
	rep(i, 0, m) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tmp1--;
		tmp2--;
		adjlist[tmp1].push_back(tmp2);
		adjlist[tmp2].push_back(tmp1);
	}
	pq.push(0);
	visited.insert(0);
	while (!pq.empty()) {
		int tmp = pq.top();
		pq.pop();
		BFS(tmp);
	}
}