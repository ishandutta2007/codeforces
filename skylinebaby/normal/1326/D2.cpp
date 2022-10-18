#include<bits/stdc++.h>
using namespace std;
int z[2123456];
int manacher(const string& s) {
    string t = ".";
    for (int i = 0; i < s.length(); ++i) t += s[i], t += '.';
    int l = 0, r = 0, ans = 0;
    for (int i = 1; i < t.length(); ++i) {
        z[i] = (r > i ? min(z[2 * l - i], r - i) : 1);
        while (i - z[i] >= 0 && i + z[i] < t.length() && t[i - z[i]] == t[i + z[i]]) ++z[i];
        if (i + z[i] > r) r = i + z[i], l = i;
    }
    for (int i = 1; i < t.length(); ++i) ans = max(ans, z[i] - 1);
    return ans;
}
int main()
{
	int cc;
	scanf("%d", &cc);
	while(cc--)
	{
		string s;
		cin >> s;
		int x = manacher(s);
		int n = s.length();
		int pos1 = 0;
		int pos2 = n - 1;
		while(pos1 < pos2)
		{
			if(s[pos1] == s[pos2])
			{
				pos1++;
				pos2--;
			}
			else break;
		}
		if(pos1 >= pos2)
		{
			cout << s << '\n';
			continue;
		}
		int mx1 = 0;
		int mx2 = 0;
 		for(int i = 2 * pos1 + 1; i <= (pos1 + pos2 + 1); i++)
 		{
 			if(z[i] + 2 * pos1 >= i) mx1 = max(mx1, i - 2 * pos1); 
		}
 		for(int i = 2 * pos2 + 1; i > (pos1 + pos2 + 1); i--)
 		{
 			if(z[i] + i >= 2 * pos2 + 2) mx2 = max(mx2, 2 * pos2 + 2 - i); 
		}
		if(mx1 > mx2)
		{
			for(int i = 0; i < pos1; i++) cout << s[i];
			for(int i = pos1; i < pos1 + mx1; i++) cout << s[i];
			for(int i = pos2 + 1; i < n; i++) cout << s[i];
			cout << '\n';
		}
		else
		{
			for(int i = 0; i < pos1; i++) cout << s[n - 1 - i];
			for(int i = pos1; i < pos1 + mx2; i++) cout << s[n - 1 - i];
			for(int i = pos2 + 1; i < n; i++) cout << s[n - 1 - i];
			cout << '\n';
		}

	}
	return 0;
}