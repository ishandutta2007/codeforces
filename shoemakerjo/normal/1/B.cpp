#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	string cur;
	string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < n; i++) {
		cin >> cur;
		bool seenDig = false;
		bool type1 = false; //R23C55

		for (int j = 0; j < cur.length(); j++) {
			if (isdigit(cur[j])) seenDig = true;
			if (seenDig && cur[j]=='C') type1 = true;
		}
		if (type1) {
			vector<int> nums1;
			vector<int> nums2;
			bool seenC = false;
			for (int j = 1; j < cur.length(); j++) {
				if (cur[j]=='C') {
					seenC = true;
					continue;
				}
				if (seenC) nums2.push_back(cur[j]-'0');
				else nums1.push_back(cur[j]-'0');

			}
			int num1 = 0;
			int num2 = 0;
			for (int j = 0; j < nums1.size(); j++) {
				num1*=10;
				num1+=nums1[j];
			}
			for (int j = 0; j < nums2.size(); j++) {
				num2*=10;
				num2+=nums2[j];
			}
			// cout << num1 << " - " << num2 << endl;
			vector<int> base26;
			int curp = 1;
			int pcount = 0;
			while (curp*26 <= num2) {
				curp*=26;
				pcount ++;
			}
			curp*=26;
			for (int j = pcount; j >= 0; j--) {
				curp/=26;
				int tempo = num2/curp;
				base26.push_back(tempo);
				num2-=tempo*curp;
			}
			for (int i = 0; i < base26.size(); i++) {
				int x = i;
				while (base26[x] == 0) {
					if (x==0) break;
					base26[x] = 26;
					base26[x-1]--;
					x--;
				}
				// if (base26[i]==0) {
				// 	base26[i] = 26;
				// 	base26[i-1]--;
				// }
			}
			for (int i = 0; i < base26.size(); i++) {
				cout << alph[base26[i]-1];
			}


			// while (num2 > 0) {
			// 	int low_pow = 1;
			// 	while (low_pow*26 < num2) {
			// 		low_pow*=26;
			// 	}
			// 	int tempo = num2/low_pow;
			// 	if (num2%low_pow ==  0 && low_pow != 1) tempo--;
			// 	else if ()
			// 	if (tempo == 1 && (num2-(tempo*low_pow) 
			// 		< (low_pow/26))) {
			// 		tempo = 26;
			// 		low_pow/=26;
			// 	}
			// 	num2 -= tempo*low_pow;
			// 	cout << alph[tempo-1];
			// }
			cout << num1 << endl;
		}
		else {

			int ind = 0;
			int num1 = 0;
			while (!isdigit(cur[ind])) {
				num1*=26;
				num1 += cur[ind]-'A'+1;
				ind++;
			}
			int num2 = 0;
			while (!(ind == cur.length())) {
				num2*=10;
				num2+=cur[ind]-'0';
				ind++;
			}
			cout << 'R' << num2 << 'C' << num1 << endl;
		}
	}
	// cin >> cur;

}