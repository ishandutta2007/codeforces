s = input()
s = '.' + s
s += '.'
for i in range(0, len(s) - 3):
    z = set(s[i]+s[i+1]+s[i+2])
    if {'A', 'B', 'C'} == z:
        print('YEs')
        exit(0)
print('No')