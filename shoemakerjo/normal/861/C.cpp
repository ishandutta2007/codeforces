#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
	cin >> line;
	vector<string> words;
	int curcons = 0;
	int start = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || 
			line[i] == 'o' || line[i] == 'u') {
			curcons = 0;
		}
		else {
			curcons++;
			if (curcons == 3) {
				if (line[i-2] == line[i-1] && line[i] == line[i-1]) {
					curcons--; continue;
				}
				else {
					words.push_back(line.substr(start, i-start));
					start = i;
					curcons = 1;
				}
			}
		}
	}
	if (start != line.length()) {
		words.push_back(line.substr(start));
	}
	for (int i = 0; i < words.size(); i++) {
		if (i > 0) cout << " ";
		cout << words[i];
	}
	cout << endl;
	// cin >> start;
}