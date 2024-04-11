a = raw_input()
b = raw_input()
c = ""
for i in range(len(a)):
    if a[i] == b[i]:
        c += '0'
    else:
        c += '1'
print c