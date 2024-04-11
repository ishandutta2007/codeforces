#include<bits/stdc++.h>

using namespace std;

int ask_query(int c, int d)
{
	cout << "? " << c << " " << d << "\n";
	fflush(stdout);

	int res;

	cin >> res;

	return res;
}

int main ()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int normal = ask_query(0, 0);
	int a = 0, b = 0;

	for(int i = 29; i >= 0; i--)
	{
		int q1, q2;

		q1 = ask_query((1<<i) + a, (1<<i) + b);

		if(q1 != normal)
		{
			if(q1 == 1)
				b += (1<<i);
			else
				a += (1<<i);

			normal = ask_query(a, b);
		}
		else
		{
			q2 = ask_query((1<<i)+a, b);

			if(q2 == -1)
			{
				a += (1<<i);
				b += (1<<i);
			}
		}
	}

	cout << "! " << a << " " << b << "\n";
	fflush(stdout);

	return 0;
}