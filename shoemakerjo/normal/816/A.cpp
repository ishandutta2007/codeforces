#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(0);
	v.push_back(70);
	v.push_back(140);
	v.push_back(210);
	v.push_back(280);
	v.push_back(350);
	v.push_back(601);
	v.push_back(671);
	v.push_back(741);
	v.push_back(811);
	v.push_back(881);
	v.push_back(951);
	v.push_back(1202);
	v.push_back(1272);
	v.push_back(1342);
	v.push_back(1412);
	// v.push_back(1482);
	string cur;
	cin >> cur;
	int hour = (cur[0]-'0')*10+cur[1]-'0';
	int min = (cur[3]-'0')*10 + cur[4]-'0';
	int time = hour*60+min;
	// cout << time << endl;
	int ans = 100000000;
	int temp;
	for (int i = 0; i < v.size(); i++) {
		temp = v[i]-time;
		if (temp < 0) temp += 1440;
		if (temp < ans) ans  =temp;
	}
	cout << ans << endl;
	// cin >> time;

}