n = raw_input()
t = ""
for c in n:
	if c == "1":
		t += "40"
	elif c == "2":
		t += "60"
	elif c == "3":
		t += "44"
	elif c == "4":
		t += "46"
	elif c == "5":
		t += "42"
	elif c == "6":
		t += "64"
	elif c == "7":
		t += "66"
	elif c == "8":
		t += "62"
	elif c == "9":
		t += "24"
	elif c == "0":
		t += "26"
if t == t[::-1]:
	print "Yes"
else:
	print "No"