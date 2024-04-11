#include <iostream>
#include <vector>
using namespace std;

vector <string> split(string &str)
{
	vector <string> ret;
	string tmp = "";
	for(int i = 0; i < str.size(); i ++)
		if(str[i] == ',' || str[i] == ';')
		{
			ret.push_back(tmp);
			tmp = "";
		}
		else
			tmp += str[i];
	ret.push_back(tmp);
	return ret;
}

string join(vector <string> &vec)
{
	if(vec.size() == 0)
		return "";
	string ret = vec[0];
	for(int i = 1; i < vec.size(); i ++)
		ret += ',' + vec[i];
	return ret;
}

bool is_integer(string &str)
{
	if(str.size() == 0)
		return false;
	if(str.size() == 1 && str[0] == '0')
		return true;
	bool flag = true;
	for(int i = 0; i < str.size(); i ++)
		if(!(str[i] >= '0' && str[i] <= '9'))
			flag = false;
	if(flag && str[0] != '0')
		return true;
	return false;
}

int main()
{
	ios :: sync_with_stdio(false);
	string str;
	cin >> str;
	vector <string> vec = split(str);
	vector <string> ans1;
	vector <string> ans2;
	for(auto &str : vec)
		if(is_integer(str))
			ans1.push_back(str);
		else
			ans2.push_back(str);

	if(ans1.size())
		cout << '\"' << join(ans1) << '\"' << '\n';
	else
		cout << "-\n";

	if(ans2.size())
		cout << '\"' << join(ans2) << '\"' << '\n';
	else
		cout << "-\n";

	return 0;
}