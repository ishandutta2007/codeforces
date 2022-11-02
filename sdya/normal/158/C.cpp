#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

vector < string > path;
int n;
string mode;
string command;

void print_path() {
	printf("/");
	for (int i = 0; i < path.size(); ++i)
		cout << path[i] << "/";
	printf("\n");
}

vector < string > parse(string command) {
	string buf = "";
	vector < string > res;
	if (command.size() == 0) return res;
	command += '/';
	for (int i = 0; i < command.size(); ++i)
		if (command[i] == '/') res.push_back(buf), buf = ""; else buf += command[i];
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> mode;
		if (mode == "pwd") {
			print_path();
		} else {
			cin >> command;
			if (command[0] == '/') {
				string new_command = "";
				for (int j = 1; j < command.size(); ++j)
					new_command += command[j];
				vector < string > p = parse(new_command);
				path.clear();
				for (int j = 0; j < p.size(); ++j)
					if (p[j] == "..") path.pop_back(); else path.push_back(p[j]);
			} else {
				vector < string > p = parse(command);
				for (int j = 0; j < p.size(); ++j)
					if (p[j] == "..") path.pop_back(); else path.push_back(p[j]);
			}
		}
	}
	
	return 0;
}