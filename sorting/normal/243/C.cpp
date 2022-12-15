#include <bits/stdc++.h>

using namespace std;

const long long N = 2007;

map<long long, long long> row, col;

vector<pair<long long, long long> > pos;
bool wall[N][N];
vector<pair<long long, long long> > interval_x, interval_y;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	long long x = 0, y = 0;

	row[x] = 1;
	col[y] = 1;
	pos.push_back({x, y});

	for(long long i = 0; i < n; i++){
		char c;

		cin >> c;

		long long a;

		cin >> a;

		//cout << c << " - " << a << endl;

		switch(c){
			case 'R':
				x += a;
				break;
			case 'L':
				x -= a;
				break;
			case 'U':
				y += a;
				break;
			case 'D':
				y -= a;
				break;
		}

		row[x] = 1;
		col[y] = 1;
		pos.push_back({x, y});
	}
	interval_x.push_back({0, 0});
	{
		long long i = 0;
		for(auto it = row.begin(); true; i++){
			it->second = (int)interval_x.size();
			
			//cout << (it->first) << " " << (it->second) << endl;
			interval_x.push_back({it->first, it->first});

			pair<int, int> p;
			p.first = it->first + 1;

			++it;
			if(it == row.end()){
				break;
			}

			p.second = it->first - 1;

			if(p.first <= p.second){
				interval_x.push_back(p);
			}
		}
	}
	interval_y.push_back({0, 0});
	{
		long long i = 0;
		for(auto it = col.begin(); true; i++){
			it->second = (int)interval_y.size();
			//cout << (it->first) << " y " << (it->second) << endl;
			interval_y.push_back({it->first, it->first});

			pair<int, int> p;
			p.first = it->first + 1;

			++it;
			if(it == col.end()){
				break;
			}

			p.second = it->first - 1;

			if(p.first <= p.second){
				interval_y.push_back(p);
			}
		}
	}

	interval_x.push_back({0, 0});
	interval_y.push_back({0, 0});


	for(long long i = 0; i < (long long)pos.size() - 1; i++){
		pair<long long, long long> p1= pos[i], p2 = pos[i + 1];

		//cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
		//cout << row[p1.first] << " " << col[p1.second ] << " row col " << row[p2.first] << " " << col[p2.second] << endl;

		if(p1.first == p2.first){
			for(long long j = min(col[p1.second], col[p2.second]); j <= max(col[p1.second], col[p2.second]); j++){
				wall[row[p1.first]][j] = true;
			}
		}
		else{
			for(long long j = min(row[p1.first], row[p2.first]); j <= max(row[p1.first], row[p2.first]); j++){
				wall[j][col[p1.second]] = true;
			}
		}
	}

	int r_cnt = interval_x.size() - 1;
	int c_cnt = interval_y.size() - 1;

	//for(int i = 1; i < r_cnt; i++){
	//	for(int j = 1; j < c_cnt; j++){
	//		cout << wall[i][j];
	//	}
	//	cout << endl;
	//}
	//cout << row[0] << " " << col[0] << endl;

	stack<pair<long long, long long> > st;

	long long res = 0;

	st.push({0, 0});

	while(!st.empty()){
		pair<long long, long long> p = st.top();
		st.pop();

		//cout << p.first << ", " << p.second << endl;

		if(p.first != 0 && p.second != 0 && p.first != r_cnt && p.second != c_cnt){
			res += (interval_x[p.first].second - interval_x[p.first].first + 1) * (interval_y[p.second].second - interval_y[p.second].first + 1);
			//cout << res << endl;
		}

		vector<pair<long long, long long> > v;

		v.push_back({p.first, p.second + 1});
		v.push_back({p.first, p.second - 1});
		v.push_back({p.first + 1, p.second});
		v.push_back({p.first - 1, p.second});

		for(pair<long long, long long> to: v){
			if(to.first < 0 || to.second < 0 || to.second > c_cnt || to.first > r_cnt){
				continue;
			}

			if(!wall[to.first][to.second]){
				wall[to.first][to.second] = true;
				st.push(to);
			}
		}
	}

	long long sum = 0;

	for(long long i = 1; i < r_cnt; i++){
		for(long long j = 1; j < c_cnt; j++){
			sum += (interval_x[i].second - interval_x[i].first + 1) * (interval_y[j].second - interval_y[j].first + 1);
		}
	}

	cout << sum - res << "\n";

	return 0;
}