#include <bits/stdc++.h>

const long long N = 307;

int res[N];
int cnt;
bool f[N];

int query(int l, int r)
{
	std::cout << "? " << l << " " << r << "\n";
	std::cout.flush();

	int res;

	std::cin >> res;

	return res;
}


int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, t;

	std::cin >> n >> t;

	cnt = t;

	if(n == 1)
	{
		std::cout << "! "<< t << "\n";
		std::cout.flush();

		return 0;
	}

	bool done2 = false;

	for(int i = 2; i <= n; i++)
	{
		int one = 0, two = 0;
		bool done = false;

		int l;
			
		if(i & 1)
		{
			if((n-1 + 1) & 1)
				l = 2;
			else
				l = 1;
		}
		else
		{
			if((n-1 + 1) & 1)
				l = 1;
			else
				l = 2;
		}


		while(!done || (one & 1) || (two & 1) || (l == 2 && !done2))
		{
			
			int q = query(l, i);
			bool nice = false;

			if(i & 1)
			{
				if( abs(q-cnt) % 2 == 0)
				{

				}
				else
				{
					nice = true;
				}
			}
			else
			{
				if( abs(q-cnt) % 2 == 0)
				{
					nice = true;
				}
				else
				{

				}
			}

			if(nice)
			{
				if(one % 2 == 0 && two % 2 == 0)
				{
					res[i] = q;
					done = true;
				}

				one++;
			}
			else
			{
				
				if(l == 2 && one % 2 == 0 && two % 2 == 0)
				{
					res[1] = n-q;
					done2 = true;
				}
				two++;
			}

			//std::cout << one << " - " << two << " done - " << done << std::endl;

			cnt = q;
		}

		//std::cout << res[i] << std::endl;
	}

	int sum = 0;

	for(int i = n; i >= 2; i--)
	{
		if(res[i] - res[i-1] == 1)
			f[i] = false;
		else
			f[i] = true;

		sum += f[i];
	}

	f[1] = t - sum;

	std::cout << "! ";

	for(int i = 1; i <= n; i++)
		std::cout << f[i];

	std::cout << "\n";

	std::cout.flush();

	return 0;
}