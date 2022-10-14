n = int(input())
s = input()
s = s.lower()
al = 'qazwsxedcrfvtgbyhnujmikolp'
if len(set(al).intersection(set(s))) == 26:
    print('YES')
else:
    print('NO')