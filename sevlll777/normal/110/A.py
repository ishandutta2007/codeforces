s = input()
num = s.count('4') + s.count('7')
num = str(num)
if len(num) == num.count('4') + num.count('7'):
    print('YES')
else:
    print('NO')