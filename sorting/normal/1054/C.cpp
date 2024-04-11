#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;

int l[N], r[N];
int res[N];

vector<int> v;
int cnt[N];

int tree[N], curr_tree[N];
int n;

void update(int idx, int delta) 
{
    for (; idx <= n; idx += (idx & -idx))
        tree[idx] += delta;
}

int query(int idx) 
{
    int sum = 0;
    for (; idx > 0; idx -= (idx & -idx))
        sum += tree[idx];
    return sum;
}

bool check(int n)
{
	for(int i = 0; i < n; i++)
	{
		if(l[i] != query(n) - query(res[i]))
			return 0;
		update(res[i],1);
	}
	//cout << "hi\n";

	for(int i = 1; i <= n; i++)
	{
		if(i != 1)
			update(i, -query(i) + query(i-1));
		else
			update(i, -query(i));
	}

	for(int i = n-1; i >= 0; i--)
	{
		//cout << r[i] << " " << query(n) - query(res[i]) << endl;
		if(r[i] != query(n) - query(res[i]))
			return 0;
		update(res[i],1);
	}

	return 1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> l[i];

	for(int i = 0; i < n; i++)
		cin >> r[i];

	for(int i = 0; i < n; i++)
		l[i] += r[i];

	int no = -1, maxi = n+1, used = 0, ind = n;

	while(used < n)
	{
		maxi = n+1;
		for(int i = 0; i < n; i++)
			if(l[i] > no)
				maxi = min(maxi, l[i]);

		int curr = 0;

		for(int i = 0; i < n; i++)
			if(maxi == l[i])
			{
				curr++;
				res[i] = ind;
			}

		//cout << maxi << " " << used << " " << curr << endl;

		if(maxi != used)
		{
			cout << "NO\n";
			return 0;
		}

		used += curr;
		ind--;
		no = maxi;
	}

	for(int i = 0; i < n; i++)
		l[i] -= r[i];

	

	if(!check(n))
	{
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}