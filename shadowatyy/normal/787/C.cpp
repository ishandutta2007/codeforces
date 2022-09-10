#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 7007

int n, a, b, r;

VI R, M;

int rick[N];
int morty[N];

bitset<N> visr;
bitset<N> vism;

queue<PII> Q;

int iler[N];
int ilem[N];

void dfsm(int v);

void dfsr(int v)
{
	visr[v] = 1;

	rick[v] = -1;

	for(auto it:R)
	{
		if(!vism[(v+it)%n])
		{
			//rick[v] = max(rick[v], 0);
			continue;
		}
			
		if(rick[v]==-1)
		{
			if(morty[(v+it)%n]==-1)
				rick[v] = 1;
			/*else if(morty[(v+it)%n]==0)
				rick[v] = 0;*/
		}
		/*else if(rick[v]==0)
		{
			if(morty[(v+it)%n]==-1)
				rick[v] = 1;
		}*/
	}

	for(auto it:M)
	{
		if(!vism[(v-it+n)%n] && rick[v]!=1)
			Q.emplace((v-it+n)%n, 0); //m
		else if(!vism[(v-it+n)%n])
		{
			++ilem[(v-it+n)%n];

			if(ilem[(v-it+n)%n]==M.size())
				Q.emplace((v-it+n)%n, 0);
		}
	}
}

void dfsm(int v)
{
	vism[v] = 1;

	morty[v] = -1;

	for(auto it:M)
	{
		if(!visr[(v+it)%n])
		{
			//morty[v] = max(morty[v], 0);

			continue;
		}

		if(morty[v]==-1)
		{
			if(rick[(v+it)%n]==-1)
				morty[v] = 1;
			else if(rick[(v+it)%n]==0)
				morty[v] = 0;
		}
		/*else if(morty[v]==0)
		{
			if(rick[(v+it)%n]==1)
				morty[v] = 1;
		}*/
	}

	for(auto it:R)
	{	
		if(!visr[(v-it+n)%n] && morty[v]!=1)
			Q.emplace((v-it+n)%n, 1); //r
		else if(!visr[(v-it+n)%n])
		{
			++iler[(v-it+n)%n];

			if(iler[(v-it+n)%n]==R.size())
				Q.emplace((v-it+n)%n, 1);
		}
			
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a;

	for(int i = 1; i <= a; ++i)
	{
		cin >> r;
		R.pb(r);
	}

	cin >> b;

	for(int i = 1; i <= b; ++i)
	{
		cin >> r;
		M.pb(r);
	}

	rick[0] = -1;
	morty[0] = -1;
	visr[0] = 1;
	vism[0] = 1;

	for(auto it:R)
	{
		Q.emplace((0-it+n)%n, 1); //r
	}

	for(auto it:M)
	{
		Q.emplace((0-it+n)%n, 0); //m
	}

	while(!Q.empty())
	{
		PII v = Q.front();
		Q.pop();

		if(v.nd==1)
			dfsr(v.st);
		else
			dfsm(v.st);
	}

	for(int i = 1; i < n; ++i)
	{
		/*if(!visr[i])
		{
			rick[i] = -1;

			for(auto it:R)
			{
				if(!vism[(i+it)%n])
					rick[i] = max(rick[i], 0);

				if(morty[(i+it)%n]==-1)
					rick[i] = 1;
			}
		}*/

		if(rick[i]==1)
			cout << "Win" << " ";
		else if(rick[i]==-1)
			cout << "Lose" << " ";
		else
			cout << "Loop" << " ";
	}

	cout << endl;

	for(int i = 1; i < n; ++i)
	{	
		/*if(!vism[i])
		{
			morty[i] = -1;

			for(auto it:M)
			{
				if(!visr[(i+it)%n])
					morty[i] = max(morty[i], 0);

				if(rick[(i+it)%n]==-1)
					morty[i] = 1;
			}
		}*/

		if(morty[i]==1)
			cout << "Win" << " ";
		else if(morty[i]==-1)
			cout << "Lose" << " ";
		else
			cout << "Loop" << " ";
	}
}