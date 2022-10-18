res = '+' * ord('0')
for c in str(input()):
    d = ord(c) - ord('0')
    res += '+' * d + '.' + '-' * d
print res