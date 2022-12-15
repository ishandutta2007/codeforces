#include <bits/stdc++.h>

using namespace std;

const int N = 17;
const long double inf = 1000;

long double x[N], v[N], m[N], curr_t[N];

struct crash{
	int first, second;
	long double time;

	crash(int _first, int _second){
		//cout << _first << " --- " << _second << endl;

		first = _first;
		second = _second;

		if(first > second)
			swap(first, second);

		/*if(x[first] == x[second])
		{
			time = inf;
			return ;
		}*/

		if(curr_t[first] > curr_t[second])
			swap(first, second);

		long double f_x = x[first], s_x = x[second];
		long double start_time = curr_t[second];

		f_x += (curr_t[second] - curr_t[first]) * v[first];

		if(f_x > s_x){
			swap(first, second);
			swap(f_x, s_x);
		}

		if(v[second] >= v[first])
			time = inf;
		else{
			time = start_time;
			time += (s_x - f_x) / (v[first] - v[second]);
		}

		//cout << first << " : " << second << " " << time << endl;
	}

	friend bool operator<(crash lvalue, crash rvalue){
		//return lvalue.time < rvalue.time;

		if(lvalue.time != rvalue.time)
			return lvalue.time < rvalue.time;

		if(lvalue.first != rvalue.first)
			return lvalue.first < rvalue.first;

		return lvalue.second < rvalue.second;
	}
};

set<crash> st;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long double t;

	cin >> n >> t;

	for(int i = 0; i < n; i++)
		cin >> x[i] >> v[i] >> m[i];

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			st.insert( crash(i, j) );

	while(!st.empty() && st.begin()->time < t)
	{
		crash c = *st.begin();

		int f = c.first, s = c.second;

		for(int i = 0; i < n; i++)
		{
			if(i == f || i == s)
				continue;

			auto it = st.find( crash(i, f) );
			if(it != st.end())
				st.erase(it);

			it = st.find( crash(i, s) );
			if(it != st.end())
				st.erase(it);
		}

		st.erase( c );

		x[f] += (c.time - curr_t[f]) * v[f];
		x[s] += (c.time - curr_t[s]) * v[s];

		//cout << c.time << endl;

		//cout << x[f] << " " << x[s] << endl;

		curr_t[f] = c.time;
		curr_t[s] = c.time;

		long double v_f = ( (m[f] - m[s]) * v[f] + 2*m[s]*v[s] ) / (m[f] + m[s]);
		long double v_s = ( (m[s] - m[f]) * v[s] + 2*m[f]*v[f] ) / (m[f] + m[s]);

		v[f] = v_f;
		v[s] = v_s;

		//cout << v[f] << " " << v[s] << endl;

		for(int i = 0; i < n; i++)
		{
			if(i == f || i == s)
				continue;

			st.insert( crash(i, f) );
			st.insert( crash(i, s) );
		}

		//st.insert( crash(f, s) );

		//cout << " ---- \n";
		//cout << x[0] << " " << curr_t[0] << " " << v[0] << endl;
		//cout << x[1] << " " << curr_t[1] << " " << v[1] << endl;
		//cout << x[2] << " " << curr_t[2] << " " << v[2] << endl;
	}

	//cout << st.begin()->first << endl;

	for(int i = 0; i < n; i++){
		x[i] += (t - curr_t[i]) * v[i];
		cout << fixed << setprecision(8) << x[i] << "\n";
	}

	return 0;
}