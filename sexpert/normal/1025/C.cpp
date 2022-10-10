#include <bits/stdc++.h>
using namespace std;

int numOnes(string s)
{
    int n = s.length();
    int count = 0, ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1') count++;
        else
        {
            ret = max(ret, count);
            count = 0;
        }
    }
    return max(ret, count);
}

char inv(char c)
{
    if(c == '0') return '1';
    return '0';
}

int main()
{
	string s, conv, s1, s2;
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++)
	{
	    if(s[i] == 'w') conv += '1';
	    else conv += '0';
	}
	conv += conv;
	for(int i = 0; i < 2*n; i++)
	{
	    if(i%2)
	    {
	        s1 += conv[i];
	        s2 += inv(conv[i]);
	    }
	    else
	    {
	        s1 += inv(conv[i]);
	        s2 += conv[i];
	    }
	}
	cout << min(n, max(numOnes(s1), numOnes(s2)));
}