s = input()
st = {'a', 'e', 'i', 'o', 'u', ' '}
res = ""

def check(s):
	if (len(s) < 3):
		return True
	if (s[-1] not in st and s[-2] not in st and s[-3] not in st) and (s[-1] != s[-2] or s[-2] != s[-3] or s[-1] != s[-3]):
		return False
	return True

for item in s:
	if not check(res + item):
		res += " "
	res += item
print(res)