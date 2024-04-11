w = eval(raw_input())
s = str(w)
for c in s:
    a = ""
    for k in range(ord(c)):
        a += "+"
    a += '.>'
    print a