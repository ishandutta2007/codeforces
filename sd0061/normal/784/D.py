s = raw_input()
t = s[::-1]
w = ""
for c in t:
    if c == '0':
        w += '8'
    if c == '1':
        w += 'x'
    if c == '2':
        w += 'x'
    if c == '3':
        w += '3'
    if c == '4':
        w += '6'
    if c == '5':
        w += '9'
    if c == '6':
        w += '4'
    if c == '7':
        w += '7'
    if c == '8':
        w += '0'
    if c == '9':
        w += '5'
if w == s:
    print 'Yes'
else:
    print 'No'