#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> course_graphic;
vector<vector<int>> dependencies;
vector<int> attended;

bool attend_course(int n) {
	if (attended[n] == 1) return false;
	if (attended[n] == 2) return true;
	attended[n] = 1;
	for (int i = 0; i < dependencies[n].size(); i++) {
		if (!attend_course(dependencies[n][i])) return false;
	}
	attended[n] = 2;
	course_graphic.push_back(n);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	vector<int> main_courses;
	cin >> n >> k;
	main_courses.resize(k);
	attended.resize(n);
	dependencies.resize(n);
	for (int i = 0; i < k; i++) {
		cin >> main_courses[i];
		main_courses[i]--;
	}
	for (int i = 0; i < n; i++) {
		int nc;
		cin >> nc;
		for (int j = 0; j < nc; j++) {
			int tmp;
			cin >> tmp;
			tmp--;
			dependencies[i].push_back(tmp);
		}
	}
	for (int i = 0; i < k; i++) {
		if (!attend_course(main_courses[i])) {
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << course_graphic.size() << endl;
	for (int i = 0; i < course_graphic.size(); i++) cout << course_graphic[i] + 1 << ' ';
	cout << endl;
	return 0;
}