a = input()
b = input()
d = {}
for i in range(26):
    d[a[i]] = b[i]
    d[a[i].upper()] = b[i].upper()
s = input()
print(''.join([d[i] if i in d else i for i in s]))