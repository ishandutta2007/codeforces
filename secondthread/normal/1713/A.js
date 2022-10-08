var T = parseInt(readline());
for (var tt=0; tt<T; tt++) {
    var n = parseInt(readline());
    var minx=0;
    var maxx=0;
    var miny=0;
    var maxy=0;
    for (var i=0; i<n; i++) {
        var coords = readline().split(" ").map(x => parseInt(x));
        minx=Math.min(coords[0], minx);
        maxx=Math.max(coords[0], maxx);
        miny=Math.min(coords[1], miny);
        maxy=Math.max(coords[1], maxy);
    }
    
    print(minx*-2+maxx*2+miny*-2+maxy*2);
}