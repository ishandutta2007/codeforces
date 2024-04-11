#include <iostream>
#include <string>
using namespace std;
string a[1000];
string a2[1000];
int arr[1000][1000];
int main(){
	int h,w,k;
	cin >> h >> w >> k;
	int counter = 0;
	int counter1 = 0;
	for(int i = 0; i < h; i++){
		cin >> a[i];
		for(int j = 0; j < w-1; j++){
			if(a[i][j] == 'E'){
				counter++;
				counter1++;
			}else{
				counter1++;
			}
		}
		if(i != h-1){
			cin >> a2[i];
			for(int j = 0; j < w;j++){
				if(a2[i][j] == 'E'){
					counter++;
					counter1++;
				}else{
					counter1++;
				}
			}
		}
	}
	if(k < 1){
		cout << "NO";
		return 0;
	}
	if(k == 1){
		if((double)counter1*3 <= (double)counter*4){
			cout << "YES" << endl;
			for(int i = 0; i < h;i++){
				for(int j = 0; j < w;j++){
					cout << 1 << " ";
				}
				cout << endl;
			}
		}else{
			cout << "NO";
		}
		return 0;
	}
	cout << "YES" << endl;
	if(w > h){
		arr[0][0] = 1;
		for(int i = 1; i < w;i++){
			if(a[0][i-1] == 'E'){
				arr[0][i] = arr[0][i-1];
			}else{
				arr[0][i] = 3-arr[0][i-1];
			}
		}
		for(int i = 1; i < h;i++){
			for(int j = 0; j < w; j++){
				if(j == 0){
					if(a2[i-1][0] == 'E'){
						arr[i][j] = arr[i-1][j];
					}else{
						arr[i][j] = 3-arr[i-1][j];
					}
				}else if(a[i][j-1] == 'E'){
					arr[i][j] = arr[i][j-1];
				}else{
					arr[i][j] = 3-arr[i][j-1];
				}
			}
			int counter = 0;
			int counter1 = 0;
			for(int j = 0;j < w;j++){
				if(a2[i-1][j] == 'E' && arr[i][j] == arr[i-1][j]){
					counter++;
				}else if(a2[i-1][j] == 'N' && arr[i][j] == 3-arr[i-1][j]){
					counter++;
				}else{
					counter1++;
				}
			}
			if(counter1 > counter){
				for(int j = 0; j < w; j++){
					arr[i][j] = 3-arr[i][j];
				}
			}
		}
		for(int i = 0; i < h;i++){
			for(int j = 0; j < w; j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}else{
		arr[0][0] = 1;
		for(int i = 1; i < h;i++){
			//	cout << a2[i-1][0] << endl;
			if(a2[i-1][0] == 'E'){
				arr[i][0] = arr[i-1][0];
			}else{
				arr[i][0] = 3-arr[i-1][0];
			}
		}
		for(int i = 1; i < w;i++){
			for(int j = 0; j < h; j++){
				if(j == 0){
					//cout << a[i-1][0] << endl;
					if(a[0][i-1] == 'E'){
						arr[j][i] = arr[j][i-1];
					}else{
						arr[j][i] = 3-arr[j][i-1];
					}
				}else if(a2[j-1][i] == 'E'){
					arr[j][i] = arr[j-1][i];
				}else{
					arr[j][i] = 3-arr[j-1][i];
				}
			//	cout << " j " << j << " i " << i << " " << a2[j-1][i] << endl;
			}
			int counter = 0;
			int counter1 = 0;
			for(int j = 0;j < h;j++){
			//	cout << " j " << j << " i " << i << " " << a[j][i-1] << endl;
				if(a[j][i-1] == 'E' && arr[j][i] == arr[j][i-1]){
					counter++;
				}else if(a[j][i-1] == 'N' && arr[j][i] == 3-arr[j][i-1]){
					counter++;
				}else{
					counter1++;
				}
			}
			if(counter1 > counter){
				for(int j = 0; j < h; j++){
					arr[j][i] = 3-arr[j][i];
				}
			}
		}
		for(int i = 0; i < h;i++){
			for(int j = 0; j < w; j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}