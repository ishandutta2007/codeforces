	import java.io.BufferedReader;
	import java.io.IOException;
	import java.io.InputStreamReader;
	import java.util.StringTokenizer;
	
	public class BSpam {
		/*
	
	oooooooooooooooooooooooooooooooooooooooooooooooooddxxxxxxxkxxxxddoooooddxdddddddoodddddddddddddddddddxdddddooolllllllllllllllllllllooooolllllllllclllllllcccccccllloodddddddddddddddddxxxdoooooooooooodddooollllllllllllllccllllllllllllllllllllllllllllllllllllllllllloodddddxxddddoooooddxxxxxdddooooooooo
	ooooooooooooooooooooooooooooooooooooooooooodddddddxxkkxxkkkxxxxddooooddxxxxxxxxddddxxxxxxxxxddxxxxxxxxxxxxxxxddooooooolllllllllllooooooooooooooolllllllllllllllllooddxxxxxxxxxxxxxxxxxkkxxdooooooooooodddoooooooooooooolllllllllllllllllllllllllllllllllllloodddddddoooddxxxxkkkxxxxddodddxxkkkkxxxddddddddd
	dddddddddddddddddddddddddddddddddddddddddxxxxxxxxxkkkkOOkkxxxdddddddoddxxxkkkkkxxxxxkkxxxkkkxxkkkkkkkkkkkkkkkkxddooooooooooollloodddddddddddddddooollllllllllooodddxxxxxxxxxkxxxkkkkkkkkkkxxdddddddddddddooddddddddxxxdddddoolllllllllllllllllooooodddddddddxxxxxxxxxxxxxxkkkkkkkkkkxxdddxxkkkOkkkkkkxxddddd
	ddddddddddddddddddddddddddddddddddddddxxkkkkkkkkkkkkkkkkkxxddddddddddddxxkkkkkxxxxxxkkkxxkkkkkkkkkkkkkkkkkkkkkxddddoooooooooooooooddxxxxxxxxxxdddoooooooloodddddxxxxxxkkxxxkkkxkkkkkxkkkkkkkkxxxxxddddddddddxxxxxxxxxxdddxxdooooooooooooooooooddxxxxxxxxxxxxxxxxxkkkkkkxxkkkOOOkkOOOkkxxxxxkkOOOOOOOOOkxxxxx
	ddddxddddddddddddddddddddddddddddddxxkkkkkkkOOOkkkkOOOkxxxxxddddddddxxxxkkkkkkkxxkkkkkkkkkkkkkkOOOOOkkOOOOkkkxxdddddddooooooooooooddddodddddddddddoooooooodxdddxkkkkkkOOkkkOOOkOOOOOkOOOOOOOOOkkkkkxdddddddxxxkxxkkxxxxxxxxddoooooooooooooooddxxxxkkkkkkkkkkkkxxkkkkkkkkkkOOOOOOOOOOOkkxxxxkkOO00OOOOOkxxxxx
	xxxxxxxxdddddddddddddddddxxxxdxxxxxxkkOOOOkkOOkkkkOOOOkkxxxxxddxxxkkkkkkkkOOOkkkkkkkOOOOOOOOOOOOOOOOOOOOOOkkxxdddddddddooooooooooddoolc::::ccclooooooooodddxxdxxkkkxkkkkkkkOOkkkOOOkkOOOOOOOOOkkkOOkxdddddxxkkkkkkkkkkxxxxddoooooooooooooooooddxxxxxkkkxxkkkkxxkkkkkkOkkkkOOOOO00000OkkkkkxkkkOOOO00OOkkkkkk
	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkkOOOOOOOkkkkOOOOkxxxxxdxxkkkkkkOOOOOOOOOkxkkkkkkOOOOOOOOOOOOOOOOOOkkxxxdddddddddoooooddddddolooc:;,,,,;:::::::cccccclooddxkkkkkkkkkkkOOkkkOOOkkkOOOOOOOkkkkOkkxddddxxkkkkxxkkkkxxxxxddooooooooooooooooooddxxkkkkkkkkkkkkkkkkkkOOOkkOO00OOO00OOkkkkkkkkxxkkkOO00OOOOOOO
	xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxkkkOOkkkOOOOkkxxxxxdxkkkkkkOOOOOOOOOOkkkkOOOOOOOOOOOOOOOkkkkkxxxxxxddxxdddddooooodollol:;;::;;;,'''',''''''',,,'',;;:cloxkkkOOOkOOOOOOOOOOOOOOOOOOOOOkkOOOkxdddxxxkkkkkkkkkxxxxxxddoooooooooooooooooodddxkkkkkkkkkkkkkkOOOOOOOOOO00000000OOkkkkkkxxxxxxxxkkOOOOO000
	xxxxxxxxxxxxxxxxxxxxxxxxxxxkkkkkxxxxxxxxxxxxkkkkkOOOkkxxxxxxxxxkkOOOOOOOOOOOOOOkkkOOOOOOOOOOOOOkxxxxxxxxxxxxxxkkxdoooodddoc:;;;;,'''','''.....'..'''''''''',,;;;:coxkkkkkkkOOOkOOOOOkOOOOOOOOOkkkkxxddddddxxxxxxxxxdddddddooooddddoooooooooooooddddxxxkkkkkkkkkkkkkOOOOkkO000000000OOOOkkkxxxxxxxxxkOOOOO000
	xxxxxxxxxxxxxxxxxxxxxxxxkkOOOOOOkkxxxxxxxxxxxxkkkkOkkxxxxxxdxxxkkOkkkkkOOOOOOOOkkkOOOOOOOOOOkkkxxxxxxxxxxxxxxkkkdoooooool:,'''',''''''..'.......''''',,,''',,,;;;;:lxkkkkkkOOkkkOOOkkkkkkkkkkxxxxxxddddddddddddddddddooooooodddxddoooooooooooooooooddddxxxxxkkkkkkOOOOOkOOOOOO000000000OOOkkxxxxxxxkOOOOOO00
	xxxxxxxxxxxxxxxxxxxxxxkkOO00OO000OOkkxxxxxxxxxxxxxxxxxxxxxddxxxkkOOkkkOOOOOOOOkkkkOOOOOOOOOkxxxxxxxxxxxxxxkkkkkxdooolllc:;,''....................'''',,,,'..'',,,,;cdkOOkkOOOOOOOOOOOOOOOkxxxxxxxxxdddddddddddddddddddooooodxxxxxddddooooooooddooooooooodddddxkkkkOOOOOOOOOOO0000O00000000OkkxxxxxxkkOOOOOO0
	xxxxxxxxxxxxxxxxxxxxkkkOOOOOOOOOOOkkkkxxxxxxxddxxxxxddddddxxxxkkkkOOOOOOOOkkkkkkkkxxxkxxxxxxxxxxxxxxxxxxxkOOkxddoolllll:;;;,,''...............''...'''''''....'''',:oxkkkkkOOOOOOOOOkkOOOkkxxxxxdxxdddxxxxxxxddddddddddooddxxxkkxddddoooooooddxddoooooooooodddxxkkkOkkOOkkOOO0000000000000OOkxxxxxxxkkOOOO00
	xxxxxxxxxxxxxxxxxxkOOOOOOOOOOOOOOOOOOOkxxxxxxdxxxxxxddxxxxxxkkOOOOOOOOOkOOOOOOkkxxxxxxxxxxxxxxxxxxxxxxxkkkkxdllloool:;,'''''''''...........''''''''''..........''',:oxkkkkkOOOOOOOOOkOOOOkkxxxxxxxxxxxkkOOOkkkkkxxdddddoooddxxkkxddooooooooddxxxxdddddooooooooddxkkkkOOOkkkOOO000000OOOO000OkkxxxxxxxkkOOO0O
	xxxxxxxxxxxxxxxxxkOO000000000000000000OkxxxxxxxxxxxxxxxxxxkkOO00OOOOOOOOO000OOkxxxxxxxxxxxxxxxxxxxxxdxkkkkxdooolc:,''.....''''''............'''''''..........''',,;coxxkkkOOOOOOOOOOOOOOOkxxxxxxxxxxxkkOOOkkkOOkkkxxddooooooddxxxdoooooooooddxxkkkxddddddoooooddddxxxxxkxxkkOOOOOOO0000000OOkkxxxxxxxxkkkkkk
	xxxxxxxxxxxxxxxxxkOO0OOOOO0O0000OOO00OOkxxxxxxxxxxxxxxxxxkOOOOOOOOOOO00OOOOkkkxxxxxxxxxxxxxxxxxxxxxxxxkkkkxddo:,''.........'''''''.......'''''''''''''''..'''',,,;coddxxxkkOOOOOOOOOOOOkxxxxxxxxxxkkOOOOOOOkOOOkkkkkkxddoooooodddddoooooooodddxxxxxxdddodddoooooooodddddddxkkOOOOOOOOOO000Okkxxxxxxxxxxxxxxx
	xxxxxxxxxxxxxxkkkOO00OOOOOOOO00OOOOOOOOkkkxxxxxxxxxxxxxxkOOOOOOOOOOO000Okkxxxxxxxxxxkkkkxxxxxxxxxxxxxxkkkxddl:,''...........'''''''''''''''''''''''''''''''''',;cldddddddxxxkkOOOOkkkxxxxxxxxxxxkOOOOOOO0OOOOOOOOOOOOkxdooooooddddddoooooddddxxkkkkkkxdddddddddddooddddddddxkkOOOOOOOOOOOOOOOkkxxxxxxxxxxxxx
	xxxxxxxxxxkkkkOOO000000000000000000000OO0OOkkxxxxxxxxxxxkOOOOOOO00000OOkkxxxxxxxxxkkOOOOOOkkxxxxxxxxxxxkxol:,'''.........'''''''',,,,,,,,,,,,;;;;;;;;;;;;;,,,,;coxxdddddddxxxkkOOkkxxxxxxxxxxkkkkOO0OOOOOOOOOOOkkkkkkkxddooooooddddooodooooddxxkkkkkkkxdddddddddddddddddddddxxkOOO000000000000Okkxxxxxxxxxxx
	xxxxxxxkkkkkkOOOOO00OOOOOOOO000OOOOOOOOOOOOOkkxxxxxxxxxxkOO0000000OOOkkxxxxxxxxxxxkOOOOOOOOOkxxxxxddddxdoc;''''''.....'''''''''''',,;;;;:::ccccclllllloolllccccldkkkxkxxxddxxxxxxxxxxxxxxkkkOOOOOO00OOOOOOOOOOOkkkkkkkxxxxxdddddddddddddddoddxkkkkkkkkxddddddddddddddddddddddddxxkkOO000O000000OOkxxxxxxxxxd
	xxxxxkkOOOOkkOOOOO00OOOOOOOO000OOOO0OOOOOOOOkkkkkxxxxxxxkOO000OOOkkkxxxxxxxxxxxxxxkOOOOOOOOOOOOkkxxdddddol:,'''''.....''''''''''',,;;::ccllllllooooooooodddooooodxkkkkkkxxxxxxxxxddxxxkkOOOOOOOkOOOOOOOOOOOOOOOOkkkOkkkkkkkxxdddddddooooddoddxxkkkkkkxxddddddddddxxkkxxxddddddddddxkOO00000000000Okxxxxxxxdd
	xxxxxkOOOOOOOOOOO0000O000000000000000000000OOOOOOkxxxxxxxkkkkkxxxxxxxdddxxxxxxxxkkOOOOOOOOOOkOOOOkxxdddooc,'''.......''''''''''',,;:ccccllllllllooooooooooddooooodxkkkkkxxdddddxxddddxxkkkkkOOkkkkOOOkkkkkkkkkkkkkkkkkxxkkkxxxddddddooooddddddxkkkOOkxdddddddddxxkkkkkkxxdddddddddxxkOOOO00000000Okxxxxxxddd
	xxxxkkOOOOOkOOOOOO0OOOOOOOOO0000O0000OO000OOOOOOkkxxxxxxxxxxxxdddddxxdddxxxdxxxkkOOOOOOOOOOkkOOOOkxxddool;,''.......'''''''''',,,;::ccccclllllllllooooooooooooooooxkkOOOkxxxddddddxxxxkOOOOOOOOkkOOOOOOOOOkkkkOkkkkkkkkkkkkxxxddddddooooddooddxkkkkkxddddddxxxxxkkkkkkkkxddddddddddxxxkkO00000000Okxxxxddddx
	xxxxxkOOOOkkOOOOOO0OOOOOOOOO00OOOO00OOOOOOOOkkkkkxxxxxxxxxxxxxxxxxddddxxxxxxxxkkOOOkOOOOOOOOOOOOkkxdddoo:,''.........'''''''',,,;;::cccccllllllooooooooooooooooooodkkOOOkkkkxddddxxkkkOOOOOOOOOkkOOOOOOOOOkkkOOOkkkOOkkkkkkkxxddddddooooodooddxkkkxxdddddxxxxxxxxkkkkkkxxddddddddddddxxxkkOOO0000Okxxxddddxx
	xxxxxkOO0OOOOO0O00000000O000000000000000000OOkkkxxxxxxxxxxxxxxxxxkkkkkxxxxxxxxkkOOOOOOOOOOOOOkxxxxdddddl:,''.........'''''''',,,;;;::ccccccllllooooooooooooooooooodkkOOOkkkkxxdxxxkkkkOOOOOOOOOkkkOOkkkkkkkkkkkkkkkkkkkkkkxxddoooddoooooooooddxkkxddddddddxxkkxxxkkkkkkkxxxxxdddddddddxxxxxxkkkOkkxxddddddxk
	xxxxxkkOOOOOOOOO0000OO0OO00000000000000000OOOkxxxxxxxxxxxxxdxxxxkkOOOOOkkkxxxxxxkkkOOOOOOOOOkkxxxxxxxddl:,''.........'''''''',,,,;;::ccccccclllloooooooooooooooooodkkOOkkxxxxxxxxxxxxkkOOOOOOOOkkkOOkkkkOkkkkOOOkkkkOkkkkkkxdddddddddoooooooddddddoodddooddxxxxxkkkkkkkxxxxxxxddddddddddxxxxxxxxxdddddddddxk
	xxxxxkkOOOkkOOOOO00OOOOOOOOO000OO00OOOO00OOOkkxxxxxxxxxxxxxxddxxxkOOOOOOOOOkxxxxxxxxkkOOOOOOkxxxxxxxxxdc;,'...........'''''''',,;;:::ccccccclllllllllllllloooooooooxkkkkxxddxxxddxxddxkkOOOOOOOkkkOOOkkkOOkkkOOOOOOOOOkkkkkkxxdddddddooooooddddoooddxxddddddddxxkkkkkkkkxxxxkxdddddddddddxxxxdddddddddddddxx
	xxxxkkOOOOOOOOOO00000000000000000000000000OOOkkkxxxxxxxxkkkxxdxxxxkkOOOOOOOkxxxxxxxxxkkkOOOkxxxxxxxkkdl:,'''...........'''''',,;;:::ccccccc:cccc::::::::::ccllllccclxkkxxdddddddddxdxxkkkkkkOOkkxkkkkkkkkkkkkkOkkkkkkkkkkkkkkxxddddddoooddddddddddxxxxxddddddddxxkxxxkkkxxxxxddddddxxxkkxxxddddddddddddddddx
	xxxkkOOOOOkOOOOO000000000O0000000000O0000OOOOOOkxxxxxxxkkOOOkxxxxxxkkOOOO0OkkxxxxxxxxxxxxkkxxxxxxkkOkxl;,'''..........'''''',,;;::ccccc:::::::ccccllcccccccclllcc:codxxxddddxxxxxxdddxxxkkkOOOOkkkkkkkkkOOkkkkOkkkkkOkkkkkkkxxxddddddoooddddddddddxkkkkxxddddddxxkkkkkxxdddddodddxxkkkkkkxxddddddddddddddddx
	xxxkOOOOOkkOOOOOO0OOOOOOOOOOOOOOOOOOOOOOOOOOkkOkkxxxxxxkkOOOkkxxxxxxkkOOOOkkxxxkkxxxxxxxxxxxxxkkOOO0Oxo;''''..'''''''...''''',;;:::ccccccccccccccc:::ccllllllllc:coddddddddxxkkkkxxddddddxxxxkkxxkkOkkkOOOOkOOOOOkOOOOkkkkkkkxddddddddoooddddddddxkkkkkkxdddddddxxkkkxxdddddddddxkkkkkkOkxxddddddddddddddddd
	xxxkOOOOOOkOOOO0000000OOOO0000OO000OOO000OOOOOOOkxxxxxkkOOOOOkxxxxxxxxkkOkxxxxkkkkkkkkxxxxxxxxkkOOOOOxo:,''''',;::::;;,,''',,,;;::cccccccllllllcccccllloolllllllloddddddxxkkOOkkkkkxddddddddddddxxkkkkkkkkkkkkkkkkkkkkkkkkkxdddddddddoodoodddddxkkkkkkkkkkxdddddddddddddddodddddxkkkkkkkxxdddddxxxdddddddddx
	xxxkOOOOOkkOOOOO000OOOOOOO0000OO000OOO00OOOOOOkkxxxxxxkkOO00OOkxxxxxxxxxxxxxxxkOOOOOOOkxxxxxxxkkOOOOOkxl;,''';:::c::::::;,,,,;;:::ccccccllllllolooooooooolllllllodddddxkkkOOOOOOOOOOkxxddddddddddddxxkkkOOkkkkOkkkkkkkxxddddoooooddddoooooddddxkkOOOkkOOOOkkxdddddddoodddddddoddxkkkkkkxdddddxxkkkxddddddddx
	xxxxkkOOkkkOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOkkkxxxxddddxxkOOOOOkkxxxxxxxxxxxxxxxkOOOOOOOOOOOkxxxkkO000OOkdl;,',::::cc:::cc::;;;;::::ccccccccllllloooooooooollllllllodddxkkkkOOOOOOOOOOOkkkxddddddddddddxxkkOkkkOOOOkOOOOkxddddooodddddooodddddddxxkkkkkkkOkkkkkxdddddddddxxxdddddddxkkkxddddddxxkkkxxxdddddddx
	xxxxxxkkkkkOOOOOOOOOOOOOOO000OOOOOOOOOOOkkkxxxddddxxxkkOOOOOOOOOkkxxxxddxxxxxxkOOOOOO0000OOkxxkkOOOOOOkxoc;,,:::ccc:::::c::::::::::::cccccclllllooooooooollcccclllddxxkkkkkOOOkkOOOkkkkkkxdddddddddddddxxkkkkkkkkkkkkkxddddoooddxxddoooooodoodxxkkOOkkOOOOOOkxddddddxxkkkkxxddddddxxxdddddddxkkkkkkkxddddddx
	xxxxxxxxxxxxxxkOOOOOOOOOOOOOOOOOOOkkxxxxxxxxddddxxkkOOOOOOOOOOOOOkkkkxxddxxxxkOOOOOOOOOOOOOkxxxkkOOOOOkkxoc;,;::ccccc:::cc:::::::::::::ccccccllllooooooollccccllllodxxkkkkkOOOOkOOOOOOOOkkddddddddddoodddxxkkkkkkkkkxxdddooooddxxddooodooooooddxkOOkkkOOOOOOkxdddxkkOOOkkkkxxdddddddddddddddxkkkkOOkxddddddx
	xxxxxxxxxxxxxxkkOOOOOOOOOOOOOOOOOkxxdxxxddddddddxxkkkkkkkkkOOOOOOOOOOkxxxxxxxkOOOOOOOO0000OOkxxxkOOOOOOOkxl:,,,;:cccccc::c::::::::::::::cccccclllllooooolc:cc::::codxkkkkkkOOOkkkOOOkkkOkkxdddddoooooooddxxkkkkkkxxddddoooddxxkkkxdddddddddddddxkkkkkkkkkkkkxdddxkkOOOOOkkkxxxdddddddddddddxkkkkkkkxdddddddd
	xxxxxxxxxxxxxxkkOOOOOOOOOOOOOOOOOkxxxxxxdddddddddxxxxxxdddxxkkkkkkkkkxxxddxxxxkOOOOOOO0000OOkxxxkOOOOOOOOkdl:,,,;::ccclccc::::::::::::::cccccclllllooooollcccc:ccodxxkkkkkkkkkkkkkkkkkkkkkxxkkxdddddooooodddddddddoooooooddxxxxkkxddoodddddddddxkkkkkkOOOOOkxddxxkkkOOOOOOkkkkxdddddddddxxkkOOOkkOOkxddddddd
	xxxxxxxxxxxxxxxkkOOOOOOOOOOOOOOkkxxxxxxddddddddddddddddddddddddxxddddddddddddxxkOOOOOOOOOOOOOkxxkkOOOOOOOOkdl;,,;:::ccccc::::::::::::::ccccccclllllooooooolooooooxkxxkkkkkkOOOOOOOOkkkkkkkkkkkkxxxkkxdooooooooodoooooooooddddxxkkxddooooddoooddxkkkkkkOOOOOkxddxkkOOOOkOOOkkOOOxxddddxxkkkkOOOOOkOOOkkxxdddd
	xxxxxxxxxxxxxxxxxkkOOOOOOOOOkkxxxxdddxxxddddddddddddddddddddddddddddddddddddddxxkOOOOOOOOOO0OkxxxkOOOOOOOOOkdc;;:::::::::::::::::::::::ccccccclllllllllllooooooodxxxxkkkkkkOOOkOOOOOkkkkkkkkkkkxxxkkkxdoooooodddddddooooooooooddxxxdooooooododdxkkkkkkkkkkkxdddxkkOOOOOOOOOkOOkxxdddxxkkOOOkkkkkkxkkkkkkxddd
	xxxxxxxxxxxxxxxxxxxkkOOOOOOkxxxxxdddddddxddddddddddddddddddddddddddddddddddddddxxkkOOOOOOOOOOkxxxkkOOOOOOOOOkocc::::::::::::::::::::::::ccccccllllllcccccllllllodxxxxxxxxxkkkkkkkkkkkkkkkxxxkkkxxxkkkxddoodddxxxxxxxxddoooooooooddddoooooooooodxkkkkkkkOOOkxddxxkkOOOOO000Okkxxxddddddxxxxkkxxxdddddddxddddd
	xxxxkkkkxkkkkxxxxxxxxkOOkkxxxxxxxxxxxxxxkxxxdddddddxxxkkkkxxxxxxxdddddddxxxxddddxxkOOOOkOOOOOkxxxxkkOOOOkOOkkxolc:::::::::::::::::::::::ccccccclllllcccccccccccodxxxkkkkkkkkOkkkkkkkkkkkkkkkkkkxxxkkkxdddddxxkkkkkkOkkxxdddooooooooooooooooooddxkkOOkOOOOOkxddxkOOOOOOOOO0Okkxxxxddddddddddddddddddddddddddd
	kkkkkkkkkkOOOkkkxxxxxxkkxxdddxxxxkkkkOOOkkkkkkkxxxxxkkOOOOkkkkkkkxdddxxxxkkxdddddxxkkOOkkOOOOOkxxxkOOOOOOOOOkxdocc::::::::::::::::::::::::cccccclloollllllllllodxkkxkkkkkkkkkkkkkOOkkkkOkkkkkkkxxkkOkxdddddxkkkkkkkOkkkkkxxdooooooooooooooodoodxxkkkkkkkkkxdddxkOOOOOOOOOOkkxxxxxxdddddddddddddddddddddddddd
	OOkkkkkkkOOOOkOOkxxxxxxxxxdxxxkkkkkOOOOOkkxkkkOOkkkkkkOOOkkkkkkxxdddxxkkkkkkxdddddxxkkOOOOOOOOkkxxxkOOOOOOOOkxdolcc::::::::::::::::::::::::ccccclllllllllllllloxxxxxxkkkxxkkkkkkkkkkkkkkkkkkkOkxxxxxdddddddxkkOOOOOOkkkOOOkxddooodddddoooooooodxxkkkkkkkkxdddxxkkOOOOO000Okxxxxxxxxddddddddddddddddddddddddx
	kkOOOOkkkkOOOOOOkkxxxxxxxddxxkkkkkkOOOOOkkkkkkkkkOOOOkkkkOOOOkkxddddxkkOkkkkxdddddddxkOOOOOOOOkkxxxxxkkkkxxxxddoccc::::::::::::::::::::::::ccccccllllooooooooodddddddxxxxxkkkkkkkkkkkkkkkkxxxxxxdddddddddddxxkOOOOOkkkkOOkkxdddooodddooooodddddxkkkkkkOOkxdddxkkOOkOOOOOOkxxxxxkkkkxxddddxxkkxxkkkkkkxddddxx
	OOOOOOkkkkOOOOOOkxxxxddddddxxkkOOOOkkkkOOkkkkkkkkOOOOkkkkkkkkkxxddddxkkkkkkxxxxddddddxkkkkkkOOkxxdxxdxxxdodxdddlccc:::::::::::::::::::::::::::ccccllloooooooodddoooodxxxxkkkkkkkkkkkkkkkkkxdddddddddddddddddxxkkkkOOOOkkkkkkxxxddooooooodddddddxkkkkkkkkkxdddxkOOOOOOOOkkxxxxxxkOkkkkxddddxkkkkkkOOOOkkxxxkk
	OOOOOOkkkOOOOOOkkxxddddddddxxkkOOOOkkkkkkkkkkOOOkkkkOOOOkkkkkxxdddddxxkkkkxxkkkxxdddddxkkkkkkxxddddddddlcoxdoolccc:::::::::::::::::::::::::;;:::::cccllllllloddooooddxxxxxkkkkkkkkkkkkkkkkxdddddddddddddddddddxxxxkkOOkkkkkkkkkkxddoddoddddddddxxkkkxxxddddddxkkOOOO0OOkxxxxxxkOOOOOOkxxddxxkkkOOOOOOOOOOOOO
	OOOOkkkkkOOkkkkkkxdddddddddxkkkkkkkkOOkkkkkkkOOkkkkkkOOOkkkxddddddddxkkkkkxxkkkkkxdddddxkkkxdddddxxxdol::ldoccc::::::::::::::::::::::::::::;;;;;:::::cccclloodooooooddxxxxkkkkkkkkkkxxkkxxdodddddddddxxxxddddddddddxkkkkkkkkkkkkkxddddoodddddddxxxxxdddoooddddxkkkkOOkkxxxxxxxkOOOOOOOkxdddxxkkOOOkkOOOOOOOO
	OOOOOkkkkkOkkkkxxddddddddddxxkkkkkkkOkkkkkkkkkkkkkkkkkkkkkkxdddddddxxkkkkkxxxkxxxdddddddddddddddxxdol:;,,:ool:::::::::::::::::cccccccc::::::;;:coddddddddxxddooooooooddxxxkkkkkkkkkkkkkkxdoodddddddxxkkkkkxddddddddxkkOkkkkkkkkkkkxddddddddddddddddooooddddoodxxkkOOkxxxxxxxxkOOOOOOOkxdddddxkkkkkOOOOOOOOOO
	kOOOOkkkkkkOOkxxdddddddddddddxxkkkkkkkkOkkkkkkkkkkkkkkkkkkkxdddddddxxkkkkxxddddooooooooooodddddddoc;,'''.,colc::::::::::::::::cccccccccc::::::cldxkkkkkkkkkxdddddoooooodddxxxkkkkkkkxxdddooooodddxxkOOOOOOkxxdddddddxkkkkkkkkkkkkxdddddddoooooooooooddddxxddddddxkkkkxxxxxkkkOO0OOOOOkxddddddxxkkkOOOOOOOOOO
	OOkkkkkkkkkkkkxxxddddddddddddxxkkkkkkkkkkkkkkkkkkkkkkkkkkxxxddddodddxxxdddoooooooooooooooooooolc:;,'.....';lol::::::::::::ccccccccccccccclllllllodxxxxxxkkxxxdxxddoooooooooddxxxxxdddooooooooddxxxkOOOOOOOOOkxdddddddxkkkkkkkkkkxddddooooooodddddddddxxxxxxxddddddxxxdddxxxkkOOOO000OOkxdddddddxxkkkkkkOOOOO
	Okkkkkkkkkkkkkkkkxddddddddxxxkkkkkkkkkkkxxxkkkkkkkkkkkkkkkxxdoooooooooooooooooooooooooooollc:;,'..........,coolc:::::::::cccccccccccccclllllllllodolcoddolodddxxddddddooooooodddddooooooooooodxxxxkkOOkkOOOOkxxdddddddxxkkkkkkxddoooooooooooooooddxxxkkkkkkkxxdddddddddddxxxxxkkkOOOOOkxdddddddxxkkkkkkOOOOO
	kkkkkkkkkkkkkkkkkkxddddddxkkkkkkkkkkkkkkxxxkkkkkkkkkkkkkkkkxddooooooooooooooooooooooolc:;,'''.............':lddoc:::::::::ccclcccccccccclllllllllddl,,;;;:cclllllllooodoooooooooooooooooooooddxkxxkOOOOOOOOOOkkxddddddddxxxxxxdooooooooooooooooddxkkkkkkkkkkxddddddddddddddddxxxxxxkkkkxxddddddxxkkkkkkOOOOO
	kkkOkkxxkkkkkkkkkxxdddddxkkkkkkkkkkkkkkkkxxxxkkkkkkkxxxxkxxddoooooooooddddoooooollc:;,''...................,coddoc::::::::cccllcccccccccllllllclodxo;'',,;::::;;;;:::lddooooooooooooooooodddxxkkxxkOOOOOOOOOOOkxddddddoddxxxdoooooooooooooooooodxxkkkkkkkkkkkxddddddddddxxxddddddddddddddddddddxxxkkOOOOOOOO
	kkkkkxxxkkkkkkkxxxxdddddxxxxkkkkkkxxxxxxxxxxxxxxxxxxxxxxdddooooooooooddxxddollc:;,''.......................';loddolc::::::cclllccccccclllllllcclodxdc,',;;;;:::::;:::ldddddoooooooooddxxxxxxkkkkxxkkOOkOOOOOOOkxdddddooodddoooooddddoooooooooooddxkkkkkkkkkOOkkxdddddddddxxxxxdddddddddddddddddxxkkkkOOOOOOO
	xxkkkxxkkkkkkkkkkxxdddddxxkkkkkkkkkkkxxxxdxxxxxxxxxxxxddooooooooooooddoolc:;;,''............................,:lodddlc:::::ccllllcccccccllllc::coddxxl,',;;;;:;;:::::cll::clloooooooddxxkkkkkkOOkxkkOOOOOOOOOOOOkkxddooooooooooooddxddooooooooooddxkkkkxxkkkkkkkxddddddddxxxxkkkkxxxxddddddddddddxkkkkkkOOOOO
	dxxkkkkkkkkkkkkkkxdddddxxkkkkkkkkkkkkkxddddddddddddddooooooooooooooolc:;;,''.................................;coodddoc::::ccclllccccccllllc:;:loddxxo;,;:;;;;;;;::::coc,''',;:clooddxxxxxxxxkkkxxxkOOOOOOOOOOOOOkkxxdooooooooooooodooooooooooooddxkkkkkkkkkkkxddddddddddddxxxkkOOOOOkxxddddddddddxkkkkOOOOOO
	dddxxxxxkkkkkkkkkxdddddxxkkkkkkkkkkkxddddoooooooooooooooooooooollc:;,,''.....................................,cloddddolc:::cclllccccccllc:;,;codddddo:,;:;;;;;;::;::cl:'.......',;clodxxxxxxxxxxdxxkkkkkkkkkkkkkkkkkxdoooooooooooooooooooooooooodxxxxxxxkkkkxdddddddddddddddxxkkkkkkkkxdddddoddddddxxkkkkkkk
	dddddddddxxxkkkkxdddddddxxkkkxxxdddddoooooooooooooooooooooollc:;,''..........................................;clooddxddoc:::clllllccclcc:;,;:lddxxddoc;::;;;;;;::;::cl;'...........',:codxxkkkkxxxkkkkkkkkkkkkkkkxkkxdoooooddddooooooooooooooooddxkkxxxxxkkxxddddddddddddddddxxkkkkkOkkxxddoooooddddddxxxxxk
	dddddddddddddxxxxdddddddxxdddddooooooooooooooooooooooolcc:;;,''.............................................':llooodddddolcccllllllclc::;,;:lodddddxdl::;;;;;;;;;;::cl;'..............'',:coxkkxxxkkOOOOOOOOOOOOkkkkxdooooddxxxddooooooooooooooddxkkkkxkkkxxdoodddddddddddddddxkkkkOOOOkkxxddddddddddddddddd
	dddddddddddddddddddddddddddoooooooooooooooooodoooooooc;,'...................................................';loooddddddddolllloollcc::;;:codddddddddlc:;;;;;;;;;;::cl;'..................',:oxxdxxkkkkOOOOkOOOOkkkxddoooodxxxxxddoooooooooooooodxxkkxkkkkxxdddddddddxxxddddddxkkkkkkkkkkkkkkxxddddddddddddd
	xxxxxxxxdddddddddddddddooooooooooddddddddddxxxddooolc;'......................................................,coooddddxxdddddooolllc::::clodddddddddoc::;;;;;;;;;;::cc;'....................';ldddxxkkkkkkkkkkxxxdddoooooodxxxxxxxdooooooooooooodxxxxxkkkxxddddddddxxkkkxddddddxkkkkkkkkkkOOOOkkkxdddddddddd
	kkkkkxkkxdddddddddddddoooooooooodxxxxxxddxxxxxxxddoc;'........................................................;loddddddxdddddddolc:::clloddddddddddl;,,;;;;;;;;;;;:::c;'.....................';odxxkkkkkkkkkxddddooooooooodxxxxxxxdooooooooooooodxxkxxkkxddoddddddddxkkkkxdooddxkkkkkOOOOOOOOOOOOOkxdddddddd
	kkkkxkkkxddddddddddddoooooooooodxxxxxxxdxxxxxxxxxdc;'.........................................................':oddddddddddddoooollloddddddddddddoc,'',,,,;;;;;;;;::::,.......................,cdxxxkkkkkkkxxddoooooooooooddxxxxxdoooooooooooooodxxkkkkkxdddddddddddxxkkkxdoooddxkkkkOOOOOOOOOOOOOkxxdddddxx
	kkkxxxkkkkxxxdddddodoooooddddddxxxxxdddddxxxxxxxdl;'...........................................................';:::cc:;;;;::cclllllloodddddddddoc,'.'',;;::;;:::ccll:,.......................';oxxxxxkkkxxddoooooooooooooddxxxxddoooooooooooooodxxkkkkxddooooooooddxxkkkkxdooddxkkkkkOOOOOOOOOOOOOkxxdddxxk
	kkkkxkkOOkkkkxxdddooooodddxxxxkkkxxxxxddddddxxxdo:,'................................................................,:cc:;;;,,,;;:ccccccclodddddc,'...''''',,,,,,,;,,'.........................,cdxxxxxkxxdoooooooooooooodxxxxxxxdooooooooooooooddxxxxxddoooooooodxxkkkkkkxddodddxkkkkOOOOOO0000OOOOkxddxxkk
	kkkkkkkkkkkkkkxxddodooddxxxxxkkkxxxxxxxdddxxxdddc,'.................................................................';:cllooolc::;;,,,,'''',;cc:'..........',;::::;'...........................':oxxxxxxddoooooooooooooooddxxxxddoooooooooooooooddxxxxxdooooooooodxkkkkkkkxddooddxkkkOOOOOOOOOOOOOOkxxdddxkk
	kkkkkkkkkkkkxxxxdoooodddxxxxxxxxxxxxxxxdxxxxxxdo;'....................................................................'',;;;;::cccccccc:::::;;;,...........,:cllllc,............................,cdxxxdoooooooodddoooooooddxxddoooooooooooooooooddxxxxddooooooooodxxkxxkkkkxddoddxxkkkkOOOOOOOOOOkkxxddddxkk
	kkxxxkkkkkkkkkxxddoodddxxxxxxxxxxxxxddddxxxxxxdc,....................................................................';cclllc::;;,,,,,;;::cllloc;'.........':cccccc,............................':odddoooooooddxxddooooooodddooooodoooooooooooooddxxddoooooddooooddxkkkkkkkkxdddddxkkkkOOOOOOOOOkkxxxxdddxxk
	kkkkkkkkkkkkkxxddoooooddxxxkkxxxkkxxxxdddddddddc'.....................................................................',,;;:cloooollc::;,,''''''...........,cllllll;.............................;oddoooooooddxxxxddoooooooooooodddoooooooooooooodxxddooooddddoooooddxxxkkkkxddoddxkkOOOOOOOOkkxxxxxxxddxxkk
	kkkkkkkkkkkxxdddooooooooddxxxxxxxxxxxxddxxxxxxd:'......................................................................',,,',,,;;::clloooollc:;,..........';loooooc,.............................;ldddoooddddxxxddoooooooooooooddddoooooooooooooodxxdooooddxxdooooooooddxxkkxddodddxkkOOOOOOOkxxxxxxxxxxxkOO
	kkkxkkkkxxdddoooooooooooooooddxxxxxxxxddxxxxxdo:.......................................................................,:llllllcc:;,,,,,,;;:ccc;'.........';lollllc,.............................,cddddddxxxxxxdooooooooooooooddddddooooooooooooodddooooddxkxxdooooooodxxkkkkxdddddxkkkOOOOOOOkxxxxxxxxxxkOO
	kkxxkkkkxddddoooooooooooooooodddxxxxddddddddodo:'.......................................................................'',,,;:clloollcc:;,,''............':llloooc'.............................':oddddxxxxxxddooooooooooooooddxxxxddoooooooooooddooooodxxxxdooooooooddxkkkkkxddddxkkOOOO00OOkxxxxxxxxxxkkO
	kkxkkkkxddddooooooooooooooooodxxxxxxxxdddddoooo:.........................................................................,::;,,'',,;;:cllloolc:,..........':oooooo:'.............................';odddxxxxdddooooooddddooooooodxxxxddoooooooooooooooooddxxdoooooooooooddxxkkkxddddxxkOOOOOOkkxxxxxxxxxxxxkk
	kkxxxxxddddooooodddddoooooooooddxxxxxxddddoodoc;.........................................................................,clllccccc:;;,,,,,;;;;,..........':odddoo:'..............................,ldddddddooooooodddxxxdoooooodddxxddoooooooooooooooooooooooooddddoooooooddxxxdddddxkOOOkxxxxxxxxxkkxxxxxxx
	xxxddddddddddddddddddddoooooooooodddxddooooooc;,...........................................................................'',,,;:clooolcc:;,'............':ododoo:'..............................,cddddddoooooodddxxxxxdddooooooddxddoooooooooooooooooooooooddxxxddooooooooodddddddxxkkxxxxxxxxkkOOOkkxxxxx
	dddddddddddddxxxxxxxxxxddoooooooooooodooooool;''..........................................................................';::;,'''',,;:clllll:,..........';ccclol:'..............................'cdddddddooodddxxxxxxxxxxxdoooooodoooooooooooooooooooooooddxxxxxxxxxxdoooooooodddddxxxxxxxxxkOOOOOOOkkxxxx
	ddddddddddddxxxxxxxxxxxddooooooooooooooooodo;'............................................................................';clllcc:::;;,,'',,,,'...........',;;cc:,...............................':oddddddddddddxxxxxxxxxxxddooooooooooooooooooooooooooooddxxxxxxkkkkkkxddoddddddddddddxxxxxkO00OOOOOOOOkxx
	ddddddxxxxxxkkxxxxxxxxxxxdddddooooooooooodo:'...............................................................................''',,,;:cloollcc:;'.............',,;,'................................';oddddddddddddxxxxxxxxxxxdoooooooooooooooooooooooooooooddxxxxxkkkkkkkxdddddddddddddxxxxxxkkO0000000000Okx
	dddddxxxxxxxkxxxxxxxxxxxxxxxxddoooooooooddc,................................................................................,::;,''.'',;;:cclc:,............',,;,..................................;odddddddddxxxxxxxxxxxxxxddooooooooooooooooooooooooooddxxkkxxxxxkkkOOkxddddddddddxxxxxxxxkkOOOOO00000OOOk
	dddddxxxxxxxxxdddddddddddddddxddoooooodddl;'................................................................................';cllcc:;;;,,,''''..............',;;,..................................;lddddxxxxxxxxxxxxxxxxxxxxxxddddooooooooooooooooooddxxkkkkkkkxxkkkkkOOkkxxxddddddxxxxxxkkOO0000000000000O
	ddddddddddooooooooooooooooooooooooooooddoc'...................................................................................',,,,;;:clllllc;,.............',;;,..................................,ldddxxxxxxxxxxxxxxxxxxxxxxxxxdddoooooooooooooooodxxxxkkkkkkkkkkkOkkkkkOOOkxxddddxxxxkkOOO00000OOOOO0000O
	dddddxxxxxxxxdddddddddddddddddooooooooool,....................................................................................,::;,'..'',;::cc:'............',;;,..................................,lddddddddddddddddddddddddddddddooooooooooooooooodddxdddxxxxxxxkkkkkkkkkOkkkxdddxxxxkOOOOOO0000000OOOO000
	dddddxkkkkkkkxxxxxxxxxxxxxxxxxdooooooodl;......................................................................................,:ccc:;;,,''''...............',;;,..................................,lddddxxxxddxxxxxxxxxdddddddddddddooooooooooooooooddddddddddxxxxxxxxxxxkkxxxxxddxxxxxxkkkkkkkkkxkkxxxkkkk
	dddddxkxxxkkxxxxxxxxxxxxxxxxxxdoooooodo:'.......................................................................................,;;,,;::ccccc:,.............',;;,..................................'cddxxxxxxxxxxxxxxxxxxxxxxxxxxxxddddooooooooooooodxxxxxxxkkkkkkOOOOOOOOOOOOkxxxxxxxxxxxkkkkkkkxxxxxxxxxxx
	ddddxxkxxkkkxxxxxxxxxxxxxxxxxxdoooooddl;........................................................................................;c:,'...'',;;:;.............',;;,..................................':oddxxxxxxxxxxxxxxxxxxxxxxxxxddddddoooooooooooooddxxxxxkkxkkkkkOOOOOOOOOOOOkxxxxxxxxkOOOOO000OO000OOO00O
	ddddxkkkkkkkkxxxxxxxxxxxxxxxxxdoooodddc,.........................................................................................';:::;,,''.................',;;,...................................;oddddddxxxxxxxxdxxxxxxxxxddddoodddoooooooooooooooddddxxxkxxxxkkkOOOOOOOkkkxxxxxxxxxkOOOOO0000O0000O0000
	ddddxkkkxkkkxxxxxxxxxxxxxxxxxxdooooodo:'..........................................................................................',;,,,;;:;;,'.............',;;,...................................,cdooooodddxxxxxxxxxxxxddddooooodddooooooooooooooooooooodxxxxxxkkOOOOkxxxxxdddddxxxxkkOOOOOOOOOOOOOOOO00
	ddddxxxxxxkxxxxxxxxxxxxxxxxxxddooooodl;..........................................................................................';::;'..'',;:;'............',;;,...................................':odooooodddxxxxxxxxxxdddoooooodddddooooooooooooooooooooddxxxkkkkkOkkxxdddxxxxxxxxxxkkOOOO0000O000000000
	ddddxkkxxkkkxxxxxxxxxxxxxxxxxddoooodoc,............................................................................................',;;;,,,;;;;,'...........',;;,....................................,loooooodddxxxxxxxxxxdddoooooooddddooooooooooooooooooooddxxxkkkkOOOkxxdddxxxxxxxxxxkkOOOO00000000000000
	ddddxxxxxxkxxxxxxxxxxxxxxxxxxddoooodo;'...........................................................................................'',,;;;;::::;;,,,''.......',;;,....................................':odoooddddddxxxxxdddddooooooooddddoooooooooooooooooooooddxxkkkkkkkxxddxxxxddddxxxxxkOOOOO000O000000000
	ddddxxxxxxkxxxxxxxxxxxxxxxxxxddoooool,........................................................................................'',;;;::::::::::::::::;,'.....',;;,.....................................;oddddddddddddxxddddddooodddddddddooooooooooooooooooooooodxkkkkxxdddddxxxxxddddddxxkOOOOOOOOOO0000O000
	ddddxxxxxxxxxxxxxxxdxxxxdddxxddooodoc'............................................  .......................................'',;;;:::ccccccccc::ccccc:;,'....',;;,.....................................'cdddoododddddddddddddoddddddddddddoooooooooodddddoooooooodddxddddddddxxxxxddddddxxkOOOOO00OOO00000000
	ddddxkkxxkkxxxxxxxxxxxxxxxxxxdoooodo:'...........................................      ..................................',,,;;;;:ccccccc::::::::::::,,'....',;;'.....................................':oxddddoooddddddddddddddddddddddddooooooooooddddddooooooooodddddddddxxxkxxdddddddxkOOOOOOOOOO00000000
	ddddxxxxxkxxxxxxxxxxxxxxxxxxxdoooddl,....................................... ..       ................................'',,,,,;;;;:ccccc:::::;;;:::::;'......',,;'......................................;oxxxdddddddddddddddddddddddddddddoooooooooodddxxxddooooooddddddddxxkkkkxxxddddddxkOOOOOOOOOO0000O000
	ddddxxxxxxxxddxxxxddxxxxxxxxxdooodoc,..............................................  ................................',,,;;;;;;;;::cccccc::::::::cc:;.......',,;'......................................,ldxxxxxdddddddddddddddxxxxxdddddddooooooooooddxxxxdddooooodddddxxkkkOOOkkxxdxdddxkkOOOOOOOOOO000OO00
	ddddxxxxxxxddddxxdddxxxxxdxxddooooo:'...............................................................................',,,;;;;;;;;;::ccccccccccccccc::,.......',;;'......................................'cdxxxxxxddddddddddddddxxxxxdddddddooooooooooddxxxdxxxdddddddddxxkkkkOOOOkxddddddxkkOOOOOOOOOO0000000
	ooddxxddxxxddddxxddddxxdddxxdoooodl;'...............................................................................',,,;;;;;;;;;;::ccccccc:::c:::;,........',;;'......................................;odxxxxxxddddddddddddddddxxxdddddddooooooooodddxdddxxxxxxddddddxxkkkkkkkkxxddddddxxkOOOOOOOOOO00OOO00
	odddxxdxxxxddddddddddddddddddooodoc,................................................................................',,,;;;;;;;;;;:::cccc:::cccc:;'.........',;;'......................................;ldxxxxxxxddddddddddddddddxdddddddddodoooooodddddddddxxxxddddddxxkkkkkkkkxxddddddxxkkkkOOOOOOOOOOOOOO
	ooodddoddddooooooooooooooooooooodl;..................................................................................,,,,;;;;;;;;;::cccccccccccc:,..........',;;'......................................'cdxdxxxdddddddddddddddddddddddddddddddddooddddxxdddddxddoooodddxkkkkkkkkxxdddddddxkkkkkkOOOOOOOOOOOO
	dddddddddddoooooooooooooodddddoooc'..................................................................................',,,,,,;;;,;;:ccccccc::::::;'..........',;;'......................................'cdxxxxdddddddddddddddxxxddddddddddddddddddddddxxxxxxdddoooooddddxxkkOOkkxxdddddddxxkkkkkkkkkkkkkkkkk
	ddddddddddddddddooooodddddxxddddoc'..................................................................................',,,,,,,,,,,;::cccc::::::::,...........',;,'......................................'codddddddddddddddddddddddddddddddddddddoooodddxxddddoooooooooodddddxkkkkxdddddddddxxxxxxxxxxxxxxxxxx
	ddddddddddddddddooooddddddxxxddddl,.......................................................... .......................',,,,,,,,,,,;;::ccc:::::::;'...........',;,........................................';codddddddddddddddddddddddddddddddddddoooodddddddooooooooooooddddddxkkkkxdddddddxxkkkkkkkxxxxkkxxxx
	oddddddddddddddddoooodddddddddoodo:'.................................................................................',,,,,,,,;;;;;::::::::::;;'............',,,...........................................,:looddddddddddddddddddddddddddddddddddddddxxddoooooooddddooddddddxkkkxddddddxxkkkkkkOkkkkkOOkkkO
	oddddddxxxxddddxddooooooddddddooodl,.................................................................................'',,,,,,,,,,,;;;;;;;,,,,'..............',,,..............................................',;:cloddddddddddddddddddddddddddddddddddddoooooooddxxxdddddddddxxxxddddddxxkkkkkkkkkkkkkkkkkk
	odddddxxxxxxxxxxxdddddddddxxddooodoc'.................................................................................''''''''''''''''......................',,,....................................................,;clddddddddddddolcccclodddddddddddddooooodddxxxxxxxdddddddddddddddddxkkkkkkkkkkkkkkxxxk
	odddddxxxxxxxxxxxxddddddddddddoooodo;................................................................................................... ...................',,'.......................  ..............................,;codddddolc:;,,,;:lodddddddddddddooooddxxxxxxkkkxddddddddddddddddxkkkkkkkkkkkkkkxxxk
	odddddxxxxxxxxxxxddddddddddddoooooool,................................................................................  ................  ..................',,'.......................  .................................,;:cc:;,,,,,,;;:clloooooddddddddodddxxxxxxxxkkkxddddoooooooooddxxkkkkkkkkxkkkxxxxk
	ddddxxxxxxxxxxxxxxdddddddddddooooooooc,..............................................................................   ..    ........... ..................',,'......................   ...............   ... .... .........'''',,,,;;:::::ccccccclllooodddddxxxxxxxxxxxdooooooooooooooddxxxxxkkkxxxxxxxxxk
	oddddxxxxxxxxxxxxxxddddddxdddoooooooddl;'..............................................................'..................    ..............''..............',,'......................   .............     ..   ..  ........'',,,,;;;::cccc:::::::::::::cllooddxxxxxxxxxddooooooooooooooodxxxxxxxxxxxxxdxxxx
	odddddxxxxxxxxxxxddddddddddddooooooodddo:,...........................................................','..................    ..............................',,'.....................     ............              .......''',,,;;;::::::::;;;;;;;;;;;;;::clloddxxxxxxxxxxddddoooooooooodxxxxxxxxxxxxxxxxxx
	oddddddddddddddddoooooooooooooooooooddddolc;,'........................................................'..................      .............................',,'.....................      ...........                .....''',,,;;;;;;;;;;;;;;;;;;;;;::cccccccclooddxxxxxxdddddoooooooooddxxxxxxxxxxddxxxdd
	odddddddddooooooooooooooooooooooooooooddddddoollc::;;,,,,'''............................................. ...    .......       ...............    .. .......',,'.....................              .....             ......''',,,,;;;;;;;;;;;;;;;;;::::clloooollllloddxxddddddddoooooooooodddddddddddddddddo
	odddddddddoooooooooooooooooooooooooooodddddddddddddddddooooolllllllccc;'..........................        .       .........     ...............  ...........',,'....................                .....           .......''',,,,;;;;;;;;;;;;;;;;;;;:::::::cclooddddddddddddooooooooooooooooooooooooooooooo
	ooododddoooooooooooooooooooooooooooooodddddddddddddddddddddddddddoooddl,............................  ...... .    ..........    ................ ...........',,'.......................              ....     ..... .......'',,,,,;;;;;;::::;;;;;;;;;;::cccc:::ccloddddddddddddddooooooooodddddddddooooooooo
	ooooooooooooooooooooooooooooooooooooooddddddddddddddddddddddddddooooodl;..................................   ...............     ............... ...........',,'....................';;'.....        ......................'',,,,;;;;;;;:::::::::;;;;::::cclllcccloodddddddddddddoooooooooddddddddddddoooooo
	oodddddddooooooooooooooooooooooooooooooodddddddddddddddddddddddoooooool;.....................................................     ..........................',,'....................,loolc:,......................    ......'',,,,;;;;;;;;;;::::;;::::::;;;;;::clloddddddddddddddooooooooodddddddddddddddddd
	ooddddddoooooooooooooooooooooooooooooooodddddddddddddddddddddddoooooooo;'.....................................................    ...........',''''''''''...',,,....................,coddddolc:,'.................. ..........',,,,;;;;;;;;;;;;;;;::cloolc:;;;:clodddddddddddddddoooooooooddddddddddddddoodd
	oooooooooooooooooooooooooooooooooooooooodddddddddddddddddddddddoooooooo;'.....................................................     .........';;;;;,,,,,''...',,,....................':oddddddddolc:,'............................'',,;;;;;;;;;;;;;;::cloddoollloodddddddddddddddddoooooooodddddddddddddddooo
	ooooooooooooooooooooooooooooooooooooooooooodddddddddddddddddooooooooool;.......................................................     ........';:;;;,,,,,,''..',,,.....................;oddddddddddddoll:;,..............................',;::cc:::::;;;:cloddddddddddddddddddddddddoooooooodddddddddddddddddd
	ooooooooooooooooooooooooooooooooooooooooddddddddddddddddddooooooooooool;.......................................................      ........;:::;;,,,,,,'''',;,.....................,ldddddddddddddddddolc:,'..........................':lddddddolc:::cloddxdddddddddddddddddddddoooooooodddddddddddddddooo
	oooooooooooooooooooooooooooooooooooooooddddddddddddddddddddoooooooooooc;......................................................       ........,:::;;,,,,,,,'',,;,.....................':odddddddddddddddddddddol:;,'.....................;lddxxxddddolllooddddddddddddddddddddddddddddddddddddddddddddddddooo
	ooooooooooooooooooooooooooooooooooooooooooodddddddddddddddooooooooooolc,.......................................................       .......,:::;;;;,,,,,'',,;,......................,ldddddddddddddddddddddddddool:;,'...............';ldxxddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
	oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooool:,........................................................        .....,::::;;;;,,,,,,,,;'.......................;ldddddddddddddddddddddddddddddoolc:;,'.........;lodxxddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
	oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooc;'.........................................................        ....,:::::;;;;,,,,,,,;'.......................':oddddddddddddddddddddddddddddddddddolc:;,''',:lddxxdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
	ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo:'..........................................................        ....,:::::;;;,,,,,,,,;'........................;oddddddddddddddddddddddddddddddddddddddddoooodddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
	ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooool;'..........................................................         ...,::::::;;,,,,;,,,,'........................;ldddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
	ooooooooloolooooloolloooooooooooooooooooooooooooooooooooooooooooooool;.......................................................              ..';:::::;;,,,;;,,,,'........................,loddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
	llllllllllllllllllllllllllllllllllloooooooooooooooooooooooooooooooool,..................................................                   ..';:::::;;,,,,,,,,,'........................,cooodddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddoooooooooooooooooooooooo
	llllllllllllllllllllllllllllllllllllllllllllllloooooooooooooooooooooc,............................................                          .';:::::;;,,,,,,,,,'........     . .........'coooooooooodddddddddddddddddddddddddddddddddddddddddooooooooooooooodooooooooooooooooooooooooooooooooooooooooooooooo
	lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllloollooolc'..........................................                            .';;::::;;;,,,,,',,,............     .. ....':looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
	ccccccccccccccccccccccccccccccccccclllllllllllllllllllllllllllllllll:'.........................................                             .',;;;;;;;;,,,,''','........''...        ...':llllloooooooooooooooooooooooooooooooooooooooooooollllllllllllllllllllllllllllllllllllllollllllllllllllllllllllllll
	cccccccccccccccccccccccccccccccccccccccccccccccccccccccccclllllllllc;...................................   ..                               ..,;;;;;;;;,,,,''',''.......''..         ....;clllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
	
	
	1
	1
	81
	9
	
	10^6==1
	1_000_000
	1
	
	64
	1
	
	2^6 == 1
	
	65
	
	
		 */
		public static void main(String[] args) {
			//D M C A
			//500 1000 100 
			FastScanner fs=new FastScanner();
			int next=fs.nextInt();
	
//			if (next==1) System.out.println(1);
//			else if (next==81) System.out.println(9);
//			else if (next==1000_000) System.out.println(1);
//			
//			else if (next==64) System.out.println(1);
//			//[64, 67)
//			else if (next==65) {
//				System.out.println(2);
//			}
//			else throw null;
			while (next>=10) {
				int sum=0;
				for (char c:(next+"").toCharArray()) {
					sum+=c-'0';
				}
				next=sum;
			}
			System.out.println(next);
		}
		
		static class FastScanner {
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st=new StringTokenizer("");
			public String next() {
				while (!st.hasMoreElements())
					try {
						st=new StringTokenizer(br.readLine());
					} catch (IOException e) {
						e.printStackTrace();
					}
				return st.nextToken();
			}
			
			int[] readArray(int n) {
				int[] a=new int[n]; 
				for (int i=0; i<n; i++) a[i]=nextInt();
				return a;
			}
			
			int nextInt () {
				return Integer.parseInt(next());
			}
		}
	
	}