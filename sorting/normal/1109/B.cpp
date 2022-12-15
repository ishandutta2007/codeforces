#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;

	cin >> s;

	bool diff = false;

	for(int i = 0; i < (int)s.size() - 1; i++){
		if(s[i] != s[i+1]){
			if((int)s.size() & 1){
				int x = (int)s.size() / 2 - i;

				if(x == 0 || x == 1){
					continue;
				}
			}

			diff = true;
			break;
		}
	}

	if((int)s.size() & 1){
		if(s[0] != s[(int)s.size() - 1]){
			diff = true;
		}
	}

	if(!diff){
		cout << "Impossible\n";

		return 0;
	}


	for(int i = 1; i < (int)s.size() - 1; i++){
		string l = s;
		string r = s;

		l.erase(i, s.size() - i);
		r.erase(0, i);

		r += l;

		//cout << r << endl;

		bool ok = true;

		for(int j = 0; j < (int)r.size() / 2; j++){
			if(r[j] != r[r.size() - j -1]){
				ok = false;
				break;
			}
		}

		if(ok && r != s){
			cout << "1\n";

			return 0;
		}
	}

	cout << "2\n";

	return 0;
}