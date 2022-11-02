#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int s, m, l, xl, xxl;

int main()
{
	cin >> s >> m >> l >> xl >> xxl;
	int k;
	cin >> k;
	for (int i = 1; i <= k; i ++)
	{
		string buf;
		cin >> buf;
		if (buf == "S")
		{
			if (s > 0) {cout << "S" << endl; s --;} else
				if (m > 0) {cout << "M" << endl; m --;} else
					if (l > 0) {cout << "L" << endl; l --;} else
						if (xl > 0) {cout << "XL" << endl; xl --;} else
							if (xxl > 0) {cout << "XXL" << endl; xxl --;}
		} 
		if (buf == "M")
		{
			if (m > 0) {cout << "M" << endl; m --;} else
				if (l > 0) {cout << "L" << endl; l --;} else
					if (s > 0) {cout << "S" << endl; s --;} else
						if (xl > 0) {cout << "XL" << endl; xl --;} else
							if (xxl > 0) {cout << "XXL" << endl; xxl --;}
		}
		if (buf == "L")
		{
			if (l > 0) {cout << "L" << endl; l --;} else
				if (xl > 0) {cout << "XL" << endl; xl --;} else
					if (m > 0) {cout << "M" << endl; m --;} else
						if (xxl > 0) {cout << "XXL" << endl; xxl --;} else
							if (s > 0) {cout << "S" << endl; s --;} 
		}
		if (buf == "XL")
		{
			if (xl > 0) {cout << "XL" << endl; xl --;} else
				if (xxl > 0) {cout << "XXL" << endl; xxl --;} else
					if (l > 0) {cout << "L" << endl; l --;} else
						if (m > 0) {cout << "M" << endl; m --;} else
							if (s > 0) {cout << "S" << endl; s --;}
		}
		if (buf == "XXL")
		{
			if (xxl > 0) {cout << "XXL" << endl; xxl --;} else
				if (xl > 0) {cout << "XL" << endl; xl --;} else
					if (l > 0) {cout << "L" << endl; l --;} else
						if (m > 0) {cout << "M" << endl; m --;} else
							if (s > 0) {cout << "S" << endl; s --;}
		}
	}
	return 0;
}